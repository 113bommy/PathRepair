n=int(input())
for i in range(n):
    x,y,a,b=input().split()
    x=int(x)
    y=int(y)
    a=int(a)
    b=int(b)
    if int((y-x)/(a+b))==float((y-x)/(a+b)):
        print(int((y-x)/(a+b)))
    else:
        print(-1)