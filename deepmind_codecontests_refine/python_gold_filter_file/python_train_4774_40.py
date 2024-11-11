INF = 10 ** 5
N, Ma, Mb = map(int,input().split())
dp = [[[INF for i in range(10 * N + 1)] for j in range(10 * N + 1)] for k in range(N+1)]
dp[0][0][0] = 0

for i in range(N):
    a, b, c = map(int,input().split())
    for j in range(10 * N + 1):
        for k in range(10 * N + 1):
            dp[i+1][j][k] = min(dp[i][j][k], dp[i+1][j][k])
            if j + a <= 10 * N and k + b <= 10 * N:
                dp[i+1][j+a][k+b] = min(dp[i][j][k] + c, dp[i+1][j+a][k+b])

ans = INF
i = 1
while Ma * i <= 10 * N and Mb * i <= 10 * N:
    ans = min(ans, dp[N][Ma*i][Mb*i])
    i += 1

if ans == INF:
    print(-1)
else:
    print(ans)