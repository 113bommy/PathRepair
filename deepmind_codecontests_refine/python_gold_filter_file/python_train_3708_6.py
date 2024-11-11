n,p,q,r=map(int,input().split())
a=list(map(int,input().split()))
px=qx=rx=-10e20
for i in range(n):
    px=max(px,p*a[i])
    qx=max(qx,px+q*a[i])
    rx=max(rx,qx+r*a[i])
print(rx)