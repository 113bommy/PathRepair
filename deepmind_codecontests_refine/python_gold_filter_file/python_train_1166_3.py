#wap to maximize the cost of suits
if __name__=='__main__':
    a=int(input())
    b=int(input())
    c=int(input())
    d=int(input())
    e=int(input())
    f=int(input())
    cost=0
    if e>f:
        if d>a:
            cost+=a*e
            d=d-a
            y=min(b,d,c)
            cost+=y*f
        else:
            cost+=d*e
            d=0
    else:
        y=min(b,d,c)
        cost+=y*f
        d=d-y
        x=min(d,a)
        cost+=x*e
    print(cost)
