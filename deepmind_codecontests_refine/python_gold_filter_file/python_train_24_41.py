for _ in range(int(input())):
    n=int(input())
    k=list(map(int,input().split()))
    if k[0]+k[1]<=k[n-1]:
        print(1,2,n)
    else:
        print(-1)
