n,k=map(int,input().split())
if not k&1:exit(print(-1))
k-=1
a=[int(i+1) for i in range(n)]
def f(l,r):
    global k
    if k<2or r-l<2:return
    k-=2
    m=(l+r)//2
    a[m],a[m-1]=a[m-1],a[m]
    f(l,m)
    f(m,r)
f(0,n)
if k:exit(print(-1))
for i in a:
    print(int(i),end=' ')

