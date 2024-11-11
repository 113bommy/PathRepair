# -*- coding: utf-8 -*-
def inpl(): return map(int, input().split())

N, Ma, Mb = inpl()
INF = 4001

DP = [[INF]*(411) for _ in range(411)]
DP[0][0] = 0

for _ in range(N):
    DP2 = [[INF]*(411) for _ in range(411)]
    a, b, c = inpl()
    for i in range(400):
        for j in range(400):
            DP2[i][j] = min(DP[i][j], DP2[i][j])
            DP2[i+a][j+b] = min(DP[i+a][j+b], DP[i][j] + c)
    DP = DP2

x = 1
ans = INF
while Ma*x <= 400 and Mb*x <= 400:
    ans = min(ans, DP[Ma*x][Mb*x])
    
    x += 1

if ans < INF:
    print(ans)
else:
    print(-1)