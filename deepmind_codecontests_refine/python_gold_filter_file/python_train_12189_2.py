# AOJ GRL_1_A
# http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A

from heapq import heappush, heappop

INF = 10000000000

def solve(r, v, dic):
    dp = []
    q = []
    dp = [INF] * v
    dp[r] = 0
    heappush(q, (0, r))
    while q:
        cost, vtx = heappop(q)
        if dp[vtx] < cost:
            continue
        if vtx not in dic:
            continue
        for vtx1, cost1 in dic[vtx]:
            if cost + cost1 < dp[vtx1]:
                dp[vtx1] = cost + cost1
                heappush(q, (cost + cost1, vtx1))
    return dp

dic = {}
dp = []
line = input()
v, e, r = list(map(int, line.split()))
for _ in range(0, e):
    line = input()
    s, t, d = list(map(int, line.split()))
    if s not in dic:
        dic[s] = [[t, d]]
    else:
        dic[s] += [[t, d]]
dp = solve(r, v, dic)
for t in range(0, v):
    print(dp[t] if dp[t] != INF else "INF")
