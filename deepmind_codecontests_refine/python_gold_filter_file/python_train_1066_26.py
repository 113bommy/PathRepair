for _ in range(int(input())):
    a, b,c = map(int, input().split())
    mn=b;mx=b
    for i in range(c):
        x,y = map(int, input().split())
        flg=0
        if(x<= mn and y>=mn) or (x<=mx and y>=mx):
            mn=min(x,mn);mx=max(y,mx)
    print((mx-mn)+1)