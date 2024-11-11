n,m,R = map(int,input().split())
r = list(map(int,input().split()))
INF = 10**10
d = [[INF for i in range(n)] for j in range(n)]

for i in range(m):
    a,b,c = map(int,input().split())
    d[a-1][b-1] = c
    d[b-1][a-1] = c

for k in range(n):
    for i in range(n):
        for j in range(n):
            d[i][j] = min(d[i][j],d[i][k]+d[k][j])

from itertools import permutations

ans = INF
for v in permutations(r,R):
    dis = 0
    for i in range(R-1):
        dis += d[v[i]-1][v[i+1]-1]
    ans = min(ans,dis)

print(ans)
