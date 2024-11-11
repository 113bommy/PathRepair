import math
t=int(input())
while t>0:
    t-=1
    d=int(input())
    if d==0:
        print("Y",0,0)
    elif d*d < 4*d:
        print("N")
    else:
        x1=d-math.sqrt(d*d-4*d)
        x1/=2;
        x2=d+math.sqrt(d*d-4*d)
        x2/=2;
        if(x1<0):
            x1=x2
        y1=x1/(x1-1)
        y2=x2/(x2-1)
        if(y1<0):
            y1=y2
        elif(y2<0):
            y2=y1
        if(y2<0):
            print("N")
        else:
            if(abs(x1+y1-x1*y1)<=1e-6 and abs(d-(x1+y1))<=1e-6):
                print("Y",x1,y1)
            elif(abs(x2+y2-x2*y2)<=1e-6 and abs(d-(x2+y2))<=1e-6):
                print("Y",x2,y2)
            else:
                print("N")
