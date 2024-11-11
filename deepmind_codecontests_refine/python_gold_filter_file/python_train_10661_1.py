n,k=map(int,input().split())
if n==k:
    print(-1)
else:
    a=[0]*n
    for i in range(n-1,n-k-1,-1):
        a[i]=i+1
    for i in range(n-k-1,0,-1):
        a[i]=i
    a[0]=n-k
    print(*a)
