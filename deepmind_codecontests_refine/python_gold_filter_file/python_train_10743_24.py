for _ in range(int(input())):
    n, m = map(int, input().split())
    cost = list(map(int, input().split()))
    index1=0
    index2=0
    cost.sort()
    cost_org=cost[0:n:1]
    for i in range(n):
        if cost_org[i] == cost[0]:
            index1=i
        if cost_org[i] == cost[1]:
            index2=i
    if m < n or n <= 2  :
        print(-1)
    else:
        m -= n
        money = 2*(sum(cost))
        money += m*(cost[0]+cost[1])
        print(money)
        for i in range(n-1):
            print(str(i+1)+' '+str(i+2))
        print(str(1)+' '+str(n))
        for i in range(m):
            print(str(index1+1)+' '+str(index2+1))
