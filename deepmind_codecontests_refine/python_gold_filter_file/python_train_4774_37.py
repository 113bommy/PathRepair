import itertools
N, Ma, Mb = map(int, input().split())
L = [[int(i) for i in input().split()] for _ in range(N)]

inf = N * 101
dp = [[[inf for _ in range(N*10+11)] for _ in range(N*10+11)] for _ in range(N+1)]

dp[0][0][0] = 0
cmb = itertools.product(range(N), range(N*10), range(N*10))
for i, j, k in cmb:
    dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k])
    dp[i+1][j+L[i][0]][k+L[i][1]] = min(dp[i+1][j+L[i][0]][k+L[i][1]], dp[i][j][k] + L[i][2])
ans = inf
for i in range(1, N*10//max(Ma, Mb)):
    ans = min(ans, dp[N][i*Ma][i*Mb])

if ans == inf:
    print(-1)
else:
    print(ans)
