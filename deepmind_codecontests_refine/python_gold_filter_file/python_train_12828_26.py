for _ in range (int(input())):
    n,x,y=map(int,input().split())
    #print(n,x,y)
    t=max(1,min(n,x+y-n+1))
    #t=max
    u=min(n,x+y-1)
    print(t,u)