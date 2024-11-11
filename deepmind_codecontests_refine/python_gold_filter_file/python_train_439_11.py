for u in range(int(input())):
    x,y=map(int,input().split())
    if(x==0 or y==0):
        print(0)
    else:
        m=max(x,y)
        n=min(x,y)
        if(m/n>=2):
            print(n)
        else:
            print((m+n)//3)
