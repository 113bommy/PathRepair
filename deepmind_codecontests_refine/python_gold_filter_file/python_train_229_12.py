for _ in range(int(input())):
    n=int(input())
    p,c=map(int,input().split())
    flag=0
    if c>p:flag=1
    for _ in range(n-1):
        x,y=map(int,input().split())
        if x<p or y<c or (y-c>x-p) or y>x:flag=1
        p=x;c=y
    print('NO' if flag else 'YES')