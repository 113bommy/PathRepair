for _ in range(int(input())):
    n,m = map(int,input().split())
    a = list(map(int,input().split()))
    if m<n or n==2:
        print(-1)
    else:
        print(2*sum(a))
        for i in range(n):
            print(i+1,max(1,(i+2)%(n+1)))