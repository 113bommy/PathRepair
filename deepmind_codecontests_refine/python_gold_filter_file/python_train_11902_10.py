for _ in range(int(input())):
    n,x,t=map(int,input().split())
    each=min(n-1,t//x)
    ans=(each-1)*(each)//2
    print((each)*(n-each)+ans)