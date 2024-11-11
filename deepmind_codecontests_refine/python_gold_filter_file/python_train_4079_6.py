for _ in range(int(input())):
    n=int(input())
    x,y,negx,posy,posx,negy=[],[],[],[],[],[]
    for i in range(n):
        a,b,c,d,e,f=map(int,input().split())
        x.append(a)
        y.append(b)
        negx.append(c)
        posy.append(d)
        posx.append(e)
        negy.append(f)
    max_x,min_x,max_y,min_y=x[0],x[0],y[0],y[0]
    f1,f2=1,1
    a=[x[i] for i in range(n) if posx[i]==0]
    if(a):
        max_x=min(a)
    else:
        f1=0
        max_x=max(x)
    a=[x[i] for i in range(n) if negx[i]==0]
    if(a):
        min_x=max(a)
    else:
        if(f1):
            min_x=min(x)
        else:
            min_x=max(x)
    a=[y[i] for i in range(n) if posy[i]==0]
    if(a):
        max_y=min(a)
    else:
        f2=0
        max_y=max(y)
    a=[y[i] for i in range(n) if negy[i]==0]
    if(a):
        min_y=max(a)
    else:
        if(f2):
            min_y=min(y)
        else:
            min_y=max(y)
    if(max_x<min_x or max_y<min_y):
        print(0)
    else:
        print(1,max_x,min_y)



