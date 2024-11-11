import sys
sys.setrecursionlimit(500*500)

h,w=list(map(int,input().split()))
s=[[1 if c=='#' else 0 for c in input()] for _ in range(h)]
g=[[] for _ in range(h*w)]

for i in range(w):
    for j in range(h):
        for di in [-1,0,1]:
            for dj in [-1,0,1]:
                if abs(di)+abs(dj)!=1:
                    continue
                if 0<=i+di<w and 0<=j+dj<h:
                    if s[j][i]!=s[j+dj][i+di]:
                        g[j*w+i].append(i+di+(j+dj)*w)

visit=[0]*(h*w)
black=[0]*(h*w)
white=[0]*(h*w)

def rec(j,i,rj,ri):
    if s[j][i]:
        black[rj*w+ri]+=1
    else:
        white[rj*w+ri]+=1
    
    for n in g[j*w+i]:
        if visit[n]:
            continue

        visit[n]=1

        rec(n//w,n%w,rj,ri)

ans=0

for i in range(w):
    for j in range(h):
        if visit[w*j+i]:
            continue
        visit[w*j+i]=1

        rec(j,i,j,i)
        
        ans+=black[w*j+i]*white[w*j+i]

print(ans)