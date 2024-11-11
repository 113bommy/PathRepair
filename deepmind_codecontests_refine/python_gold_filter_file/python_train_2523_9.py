for xyz in range(0,int(input())):
    x,y=map(int,input().split())
    a,b=map(int,input().split())
    p1=a*(abs(x)+abs(y))
    x,y=min(x,y),max(x,y)
    p2=abs(x)*b
    p2+=(abs(y-x))*a
    print(min(p1,p2))