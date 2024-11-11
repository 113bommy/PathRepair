for t in range(int(input())):
    n,k = map(int,input().split())
    if k<=n:
        if (n-k)%2==0:
            print(0)
        else:
            print(1)
    else:
        print(abs(n-k))
