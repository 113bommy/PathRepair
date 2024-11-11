for t in range(int(input())):
    n,m=map(int,input().split())
    if m%2==0:
        print(n*(m//2))
    elif n%2==0:
        print(m*(n//2))
    else:
        if n!=1 and m!=1:
            print(((n-1)//2)*m+m//2+1)
        elif n==1:
            print(m//2+1)
        else:
            print(n//2+1)