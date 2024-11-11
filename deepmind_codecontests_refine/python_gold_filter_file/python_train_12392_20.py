while 1:
    x,y=map(int,input().split())
    if x==0 and y==0:break
    print(*[y,x] if x>y else [x,y])