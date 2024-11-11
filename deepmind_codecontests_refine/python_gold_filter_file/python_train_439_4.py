for t in range(int(input())):
    x,y=map(int,input().split())
    print(min(x,y,(x+y)//3))