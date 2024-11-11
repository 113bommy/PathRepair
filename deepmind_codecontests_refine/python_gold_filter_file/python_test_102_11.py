def f():
    n,m=map(int,input().split())
    s=input()
    xp,xn,yp,yn=0,0,0,0
    x,y=0,0
    for i in s:
        if i=="R":
            x+=1
            xp=max(xp,x)
        elif i=="L":
            x-=1
            xn=min(x,xn)
        elif i=="D":
            y+=1
            yp=max(y,yp)
        else:
            y-=1
            yn=min(y,yn)
        if xp-xn>=m or yp-yn>=n:
            if i=="L":
                xn+=1
            elif i=="U":
                yn+=1
            print(-yn+1,-xn+1)
            return
    print(-yn+1,-xn+1)
for _ in range(int(input())):
    f()