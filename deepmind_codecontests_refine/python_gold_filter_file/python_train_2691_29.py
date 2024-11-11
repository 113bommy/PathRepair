import sys
def input():
    return sys.stdin.readline()[:-1]
N,A,B=map(int,input().split())
h=[int(input()) for i in range(N)]
h.sort(reverse=1)
l,r=0,10**9
k=A-B
while l+2<r:
    m=(r-l)//2+l
    t=m*B
    c=0
    for i in h:
        if i>t:
            c+=-((-i+t)//k)
        else:
            break
    if c>m:
        l=m
    else:
        r=m+1
print(r-1)