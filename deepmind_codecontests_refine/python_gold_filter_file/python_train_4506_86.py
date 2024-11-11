for x in range(int(input())):
    a,b,c=list(map(int,input().split()))
    m=max(a,b,c)
    n=min(a,b,c)
    print(a+b+c-1)