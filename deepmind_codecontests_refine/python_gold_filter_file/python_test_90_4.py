t=int(input())
for i in range(t):
    x,y=map(int,input().split())
    if (x > y):
        print(x * 2 + y )
    elif(x==y):
        print(x)
    else:
        if (y % x == 0):
            print(x)
        else:
            z=y//x;
            x=x*z;
            print((x+y)//2)