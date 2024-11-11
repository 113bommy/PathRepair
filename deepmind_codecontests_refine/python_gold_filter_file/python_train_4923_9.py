for y in range(int(input())):
    a,b,c,d=map(int,input().split())
    val=input()
    new=[]
    final_cost=0
    for y in val:
        x=int(y)
        new.append(x)
    if d<c or d<b:
        if c<b and c+d<b:
            conversion_cost=d*(new.count(0))
            final_cost=c*a+conversion_cost
        elif b<c and b+d<c:
            conversion_cost=d*(new.count(1))
            final_cost=b*a+conversion_cost
        elif b==c:
            final_cost=b*a
        else:
            final_cost=new.count(0)*b+new.count(1)*c
    else:
        final_cost=new.count(0)*b+new.count(1)*c
    print(final_cost)   