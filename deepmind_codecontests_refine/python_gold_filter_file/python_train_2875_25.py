n,k=map(int,input().split())
if k==n or k==0:
    print(0,0)
else:
    print(1,min(k*2,n-k))