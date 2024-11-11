N,M,R = map(int,input().split())
r = list(map(int,input().split()))
INF = 10**18
d = [[INF for i in range(N)] for j in range(N)]
for i in range(M):
    a,b,c = map(int,input().split())
    d[a-1][b-1] = c
    d[b-1][a-1] = c

for i in range(N):
    d[i][i] = 0

# ワーシャルフロイド
for k in range(N):
    for i in range(N):
        for j in range(N):
            d[i][j] = min(d[i][j], d[i][k] + d[k][j])

import itertools
ans = INF
for v in itertools.permutations(r,R):
    anss = 0
    for i in range(R-1):
        anss += d[v[i]-1][v[i+1]-1]
    ans = min(ans,anss)
print(ans)