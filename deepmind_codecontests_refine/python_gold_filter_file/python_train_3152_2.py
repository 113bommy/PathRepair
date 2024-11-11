t=int(input())
while t>0:
    a,b,x,y,n=list(map(int,input().split()))
    min1=1e19
    a1=a-n
    if a1>=x:
        z=a1*b
        min1=min(min1,z)
    b1=b-n
    if b1>=y:
        z=b1*a
        min1=min(min1,z)
    n1=n-(a-x)
    if n1>=0:
        b1=b-n1
        if b1>=y:
            z=x*b1
            min1=min(min1,z)
    n1=n-(b-y)
    if n1>=0:
        a1=a-n1
        if a1>=x:
            z=y*a1
            min1=min(min1,z)
    l=(a-x)+(b-y)
    if l<=n:
        z=x*y
        min1=min(min1,z)
    print(min1)
        
    t-=1
