"""
atcoder workspace
"""
from itertools import permutations

N, M, R = map(int, input().split())
Rlist = list(map(int, input().split()))

Dmat = [[1e9] * N for i in range(N)]

for i in range(N):
    Dmat[i][i] = 0

for i in range(M):
    f, t, c = map(int, input().split())
    Dmat[f-1][t-1] = c
    Dmat[t-1][f-1] = c

for i in range(N): #mid
    for j in range(N): #from
        for k in range(N): #to
            Dmat[j][k] = min(Dmat[j][k], Dmat[j][i] + Dmat[i][k])

ans = 1e9
for p in permutations(Rlist):
    ans = min(ans, sum([Dmat[p[i]-1][p[i+1]-1] for i in range(R-1)]))

print(ans)
