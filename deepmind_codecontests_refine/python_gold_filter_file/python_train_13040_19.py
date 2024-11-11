t=int(input())
while t>0:
    t-=1
    n=int(input())
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    x=min(a)
    y=min(b)
    c=0
    for i in range(n):
        p=abs(a[i]-x)
        q=abs(b[i]-y)
        c+=max(p,q)
    print(c)