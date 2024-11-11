from sys import stdin
from heapq import heappush,heappop

while(True):
    c,n,m,s,d = map(int, stdin.readline().split())
    if not c: break
    ma = [[] for _ in range(n)]
    s -= 1
    d -= 1
    for _ in range(m):
        a,b,f = map(int, stdin.readline().split())
        a -= 1
        b -= 1
        ma[a].append([f,b])
        ma[b].append([f,a])
    cost = [[10**10]*(c+1) for _ in range(n)]
    cost[s][c] = 0
    que = [[ cost[s][c], s, c ]]
    while que:
        co, pl, ti = heappop(que)
        for fee, town in ma[pl]:
            if cost[town][ti] > co+fee:
                cost[town][ti] = co+fee
                heappush(que,[cost[town][ti],town,ti])
            if ti and cost[town][ti-1] > co+fee//2:
                cost[town][ti-1] = co+fee//2
                heappush(que,[cost[town][ti-1],town,ti-1])
    print(min(cost[d]))
