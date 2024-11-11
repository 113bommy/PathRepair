r = lambda :map(int,input().split())
r1,r2 = r()
c1,c2 = r()
d1,d2 = r()
if (r1-c1+d2)%2==0:
    x2 = (r1-c1+d2)//2
    x1 = r1-x2
    x3 = d2-x2
    x4 = c2-x2
    if (0<x1<=9 and 0<x2<=9 and 0<x3<=9 and 0<x4<=9 and x1+x3==c1 and x3+x4==r2 and x1+x4==d1):
        if len(set([x1,x2,x3,x4]))<4:
            print(-1)
        else:
            print(x1,x2)
            print(x3,x4)
    else:
        print(-1)
else:
    print(-1)