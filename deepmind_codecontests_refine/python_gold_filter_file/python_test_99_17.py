def placing(x,n):
    if x%2==0:
        if n%2==0:
            div=n//2
            if div%2!=0:
                return x+1
            else:
                return x
        else:
            div=(n+1)//2
            if div%2!=0:
                return x+1-(n+1)
            else:
                return x+n+1
    else:
        if n%2==0:
            div=n//2
            if div%2!=0:
                return x-1
            else:
                return x
        else:
            div=(n+1)//2
            if div%2!=0:
                return x-1+n+1
            else:
                return x-(n+1)
t=int(input())
for i in range(t):
    x,n=map(int,input().split())
    print(placing(x,n))
    