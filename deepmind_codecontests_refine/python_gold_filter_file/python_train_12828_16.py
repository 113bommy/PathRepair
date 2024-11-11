for _ in range(int(input())):
    n,x,y=map(int,input().split())
    if((x+y)==(n+1)):
        print(min(n,2),n)
    elif((x+y)>(n+1)):
        if(x==n and y==n):
            print(n,n)
        else:
            print((x+y+1)-n,n)   
    else:
        print(1,(x+y-1))