from itertools import permutations
n, m, r = map(int, input().split())
goals = list(map(int, input().split()))
goals = [g-1 for g in goals]

g = [[pow(10, 16)] * n for i in range(n)]

for i in range(m):
    a, b , c = map(int,input().split())
    a-=1; b-=1
    g[a][b] = c
    g[b][a] = c

for i in range(n):
    for s in range(n):
        for t in range(n):
            g[s][t] = min(g[s][t], g[s][i] + g[i][t])

ans = float('inf')
for p in permutations(goals):
    cost = 0
    for s,t in zip(p[:-1], p[1:]):
        cost += g[s][t]
    ans = min(ans, cost)
print(ans)
