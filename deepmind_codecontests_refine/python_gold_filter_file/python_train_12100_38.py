for _ in range(int(input())):
    x,y,a,b = list(map(int,input().split()))
    t = (y-x)/(a+b)
    if(t==int(t)):
        print(int(t))
    else:
        print("-1")