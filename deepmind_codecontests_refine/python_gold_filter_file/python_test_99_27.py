for _ in range(int(input())):
    x,n=map(int,input().split())
    if(x%2==0):
        if(n%4==0):
            print(x)
        elif n%4==1:
            print(x-n)
        elif n%4==2:
            print(x+1)
        else:
            print(x+n+1)
    else:
        if n%4==0:
            print(x)
        elif n%4==1:
            print(x+n)
        elif n%4==2:
            print(x-1)
        else:
            print(x-n-1)
