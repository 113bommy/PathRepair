N,K=map(int,input().split())
A,F=[list(map(int,input().split())) for i in range(2)]
A.sort()
F.sort()
l,r=-1,10**18
while r-l>1:
    h=(l+r)//2
    k=0
    for i in range(N):
        k+=max(0,A[i]-h//F[-i-1])
        if k>K:
            k=-1
            break
    if k>=0:
        r=h
    else:
        l=h
print(r)