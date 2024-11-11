for _ in range(int(input())):
    n,m=map(int,input().split())
    arr=list(map(int,input().split()))
    kam=[(arr[i],i+1) for i in range(n)]
    kam.sort()
    cost=0
    extra=0
    if m<n or n<3:
        print(-1)
    else:
        cost=2*sum(arr)
        extra=m-n
        cost+=extra*(kam[0][0]+kam[1][0])
        print(cost)
        for i in range(1,n):
            print(i,i+1)
        print(n,1)
        for i in range(extra):
            print(kam[0][1],kam[1][1])



    