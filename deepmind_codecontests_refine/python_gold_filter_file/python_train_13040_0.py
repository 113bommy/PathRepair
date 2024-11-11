for _ in range(int(input())):
    n=int(input())
    a=[int(i) for i in input().split()]
    b=[int(i) for i in input().split()]
    x=min(a);y=min(b);moves=0
    for i in range(n):
        m=0
        if a[i]>x: m=a[i]-x
        if b[i]>y: m=max(b[i]-y,m)
        moves+=m
    print(moves)