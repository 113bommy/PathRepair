for _ in range(int(input())):
    n,x,t=map(int,input().split())
    d=min(n,t//x)
    print(d*(n-d)+(d*(d-1))//2)                       
