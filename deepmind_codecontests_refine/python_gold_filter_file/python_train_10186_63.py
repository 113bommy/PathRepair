from itertools import permutations
N, M, R = map(int, input().split())
r = list(map(lambda x: int(x) - 1, input().split()))
G = [[float('inf')] * N for i in range(N)]
for i in range(M):
    a, b, c = map(int, input().split())
    a, b = a - 1, b - 1
    G[a][b] = c
    G[b][a] = c


for k in range(N):
    G[k][k] = 0
    for i in range(N):
        for j in range(N):
            G[i][j] = min(G[i][j], G[i][k] + G[k][j])


ans = float('inf')
for perm in permutations(r):
    tmp = 0
    for i in range(R - 1):
        tmp += G[perm[i]][perm[i + 1]]
    ans = min(ans, tmp)

print(ans)
