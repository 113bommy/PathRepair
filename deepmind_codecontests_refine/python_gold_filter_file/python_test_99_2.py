t = int(input())
for _ in range(t):
    x,n = map(int,input().split())
    if x%2==0:
        if n%2==0:
            if (n//2)%2==0:
                print(x)
            else:
                print(x+1)
        else:
            if ((n-1)//2)%2 == 0:
                print(-n+x)
            else:
                print(n+1+x)
    else:
        if n%2==0:
            if (n//2)%2==0:
                print(x)
            else:
                print(x-1)
        else:
            if ((n-1)//2)%2 == 0:
                print(n+x)
            else:
                print(-n-1+x)
        