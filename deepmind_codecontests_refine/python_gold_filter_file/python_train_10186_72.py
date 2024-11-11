import itertools

n, m, r = map(int, input().split())
R = list(map(int, input().split()))

DP = [[10**10 for _ in range(n+1)] for _ in range(n+1)]
for i in range(1,n+1):
    DP[i][i] = 0

for _ in range(m):
    a, b, c = map(int, input().split())
    DP[a][b] = c
    DP[b][a] = c

for k in range(1,n+1):
    for i in range(1,n+1):
        for j in range(1,n+1):
            DP[i][j] = min(DP[i][j], DP[i][k]+DP[k][j])

ans = 10**10
for permutation in itertools.permutations(R, r):
    dist = 0
    for i in range(r-1):
        dist += DP[permutation[i]][permutation[i+1]]
    ans = min(ans, dist)

print(ans)