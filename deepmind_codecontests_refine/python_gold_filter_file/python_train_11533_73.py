def l():
    return [int(x) for x in input().split()]
def main():
    H,W=l()
    ch,cw=l()
    dh,dw=l()
    ch-=1
    cw-=1
    dw-=1
    dh-=1
    s=[[-2 if x=='#' else -1 for x in list(input())] for _ in range(H)]
    pad1=[-2,-2]
    pad2=[[-2]*(W+4)]*2
    s=pad2+[pad1+x+pad1 for x in s]+pad2
    move1=[(-1,0),(1,0),(0,-1),(0,1)]
    move2=list(set([(i,j) for i in range(-2,3) for j in range(-2,3)])-set(move1)-set([(0,0)]))
    q1=[(0,ch+2,cw+2)]
    q2=[]
    s[ch+2][cw+2]=0
    def mark(c,h,w):
        #if 0<=h<H and 0<=w<W and s[h][w]==-1:
        if s[h][w]==-1:
            s[h][w]=c
            q1.append((c,h,w))
    while q1:
        #print(q1)
        c,h,w=q1.pop()
        for i,j in move1:
            mark(c,h+i,w+j)
        q2.append((c+1,h,w))
        if not q1:
            for c,h,w in q2:
                for i,j in move2:
                    mark(c,h+i,w+j)
            q2=[]
    ans=s[dh+2][dw+2]
    if ans>=0:
        print(ans)
    else:
        print(-1)
main()
