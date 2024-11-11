#Ashish Sagar
q=int(input())
for _ in range(q):
    n=int(input())
    minx=-100000
    maxx=100000
    miny=-100000
    maxy=100000
    for i in range(n):
        x,y,a,b,c,d=map(int,input().split())
        if(a==0):
            minx=max(minx,x)
        if(b==0):
            maxy=min(maxy,y)
        if(c==0):
            maxx=min(maxx,x)
        if(d==0):
            miny=max(miny,y)
    if minx<=maxx and miny<=maxy:
        print(1,minx,miny)
    else:
        print(0)