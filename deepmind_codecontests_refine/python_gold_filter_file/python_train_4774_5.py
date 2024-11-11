N, Ma, Mb = map(int, input().split())
a, b, c = [0] * N, [0] * N, [0] * N
for i in range(N):
    a[i], b[i], c[i] = map(int, input().split())

S = 411
MAX_N = 10
MAX_SIZE = 400
INF = int(1e9)
dp = [[INF] * S for i in range(S)]
dp[0][0] = 0
for i in range(N):
    for j in range(MAX_SIZE, -1, -1):
        for k in range(MAX_SIZE, -1, -1):
            dp[j+a[i]][k+b[i]] = min((dp[j+a[i]][k+b[i]], dp[j][k] + c[i]))

ans = INF
for i in range(1, MAX_N):
    ans = min((ans, dp[i*Ma][i*Mb]))
if ans == INF:
    print(-1)
else:
    print(ans)