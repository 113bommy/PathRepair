for _ in range(int(input())):
    n,x,m=map(int,input().split())
    a,b=x,x
    for i in range(m):
        l,r=map(int,input().split())
        if l<=b and r>=a:
            a=min(l,a)
            b=max(r,b)
    print(b-a+1)