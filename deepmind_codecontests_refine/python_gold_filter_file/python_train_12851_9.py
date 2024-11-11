n,k=map(int,input().split())
u=0
m=0
l=list(map(int,input().split()))
for i in range(len(l)):
    if l[i]>k:
        if l[i]%k==0:
            q=(l[i]//k)-1
        else:
            q=l[i]//k
        if q>=m:
            h=i+1
            u=1
            m=q
if u==0:
    print(n)
else:
    print(h)
        