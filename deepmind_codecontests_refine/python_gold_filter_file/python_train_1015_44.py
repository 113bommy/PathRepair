import sys
input = sys.stdin.readline

N,K=map(int,input().split())
A=[int(input()) for i in range(N)]

def seg_function(x,y): # Segment treeで扱うfunction
    return max(x,y)

seg_el=1<<((300000).bit_length()) # Segment treeの台の要素数
SEG=[0]*(2*seg_el) # 1-indexedなので、要素数2*seg_el.Segment treeの初期値で初期化

def update(n,x,seg_el): # A[n]をxに更新
    i=n+seg_el
    SEG[i]=max(SEG[i],x)
    i>>=1 # 子ノードへ
    
    while i!=0:
        SEG[i]=seg_function(SEG[i*2],SEG[i*2+1])
        i>>=1
        
def getvalues(l,r): # 区間[l,r)に関するseg_functionを調べる
    L=l+seg_el
    R=r+seg_el
    ANS=0

    while L<R:
        if L & 1:
            ANS=seg_function(ANS , SEG[L])
            L+=1

        if R & 1:
            R-=1
            ANS=seg_function(ANS , SEG[R])
        L>>=1
        R>>=1

    return ANS

for a in A:
    MAX=getvalues(max(0,a-K),min(300001,a+K+1))
    update(a,MAX+1,seg_el)
print(SEG[1])
