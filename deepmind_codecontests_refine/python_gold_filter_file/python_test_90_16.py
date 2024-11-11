t=int(input())
for i in range(t):
    x,y=map(int,input().split())
    if x>y:
        print(x+y)
    elif (x==y):
        print(x)
    else:
        print(y-(y%x)//2)