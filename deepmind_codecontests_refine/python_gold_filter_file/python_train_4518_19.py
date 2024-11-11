import math
a,b,n=map(int,input().split())
if(a==b):
    print(1)
else:
    if( a==0 ):
        print("No solution")
    elif(b==0):
        print(0)
    elif(b%a!=0):
        print("No solution")
    else:
        c=a
        d=b
        a=abs(a)
        b=abs(b)
        b=b/a
        if(int(round(b ** (1. / n))) ** n == b):
            if(c*d<0):
                print('-',end="")
            print(int(round(b ** (1. / n))))
        else:
            print("No solution")