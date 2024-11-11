n,k=map(int,input().split())
mi=1
if k==0:
    print(0,0)
    exit()
if k==n:
    print(0,0)
    exit()
if 3*k <=n:
    ma=2*k
else:
    ma=n-k
print(mi,ma)
