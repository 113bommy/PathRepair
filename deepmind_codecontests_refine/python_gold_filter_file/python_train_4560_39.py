N,K=map(int,input().split())
A=list(map(int,input().split()))
F=list(map(int,input().split()))
A.sort()
F.sort(reverse=True)
l=-1
r=10**13
while r-l!=1:
    m=(l+r)//2
    x=0
    for i in range(N):
        x+=max(0,A[i]-m//F[i])
    if x<=K:
        r=m
    else:
        l=m
print(r)
