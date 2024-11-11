for _ in range(int(input())):
    x,y = map(int,input().split())
    a,b = map(int,input().split())
    if(x>y):
        l=x-y
        print(min(a*l+b*y,x*a+y*a))
    elif(x<y):
        l=y-x
        print(min(a*l+b*x,x*a+y*a))
    else:
        print(min(y*b,x*a+y*a))