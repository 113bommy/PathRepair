for i in range(int(input())):
    x,y,n = map(int,input().split())
    print(((n-y)//x)*x+y)