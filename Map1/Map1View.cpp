
// Map1View.cpp : implementation of the CMap1View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Map1.h"
#endif

#include "Map1Doc.h"
#include "Map1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMap1View

IMPLEMENT_DYNCREATE(CMap1View, CView)

BEGIN_MESSAGE_MAP(CMap1View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMap1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMap1View construction/destruction

CMap1View::CMap1View() noexcept
{
	// TODO: add construction code here

}

CMap1View::~CMap1View()
{
}

BOOL CMap1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMap1View drawing

void CMap1View::OnDraw(CDC* /*pDC*/)
{
	CMap1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMap1View printing


void CMap1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMap1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMap1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMap1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMap1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMap1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMap1View diagnostics

#ifdef _DEBUG
void CMap1View::AssertValid() const
{
	CView::AssertValid();
}

void CMap1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMap1Doc* CMap1View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMap1Doc)));
	return (CMap1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMap1View message handlers


void CMap1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	dc.SetMapMode(MM_HIENGLISH);
	CRect rect(1000, -1000, 2000, -2000);
	CPen pen(PS_SOLID, 2, RGB(255, 0, 0));
	dc.SelectObject(&pen);
	CBrush brush(HS_DIAGCROSS, RGB(0, 0, 255));
	dc.SelectObject(&brush);
	dc.Rectangle(rect);
	CView::OnLButtonDown(nFlags, point);
}
