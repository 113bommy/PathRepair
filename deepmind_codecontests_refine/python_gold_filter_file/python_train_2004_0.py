for t in range(int(input())):
    n,m,a,b=map(int,input().split())
    x=["1"]*a+["0"]*(m-a)
    if n*a==m*b:
        print("YES")
        for i in range(n):
            x=x[a:]+x[:a]
            print("".join(x))
    else:
        print("NO")