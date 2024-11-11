mod = 10 ** 9 + 7

N, K = map(int, input().split())

dp = [[[0 for _ in range(2610)] for _ in range(51)] for _ in range(51)]
dp[0][0][0] = 1

for i in range(N):
    for j in range(N):
        for k in range(K + 1):
            dp[i + 1][j + 1][k + 2 * j + 2] += dp[i][j][k]
            if j > 0:
                dp[i + 1][j][k + 2 * j] += dp[i][j][k] * j
                dp[i + 1][j][k + 2 * j] += dp[i][j][k] * j

            dp[i + 1][j][k + 2 * j] += dp[i][j][k]

            if j > 0:
                dp[i + 1][j - 1][k + 2 * j - 2] += dp[i][j][k] * j * j


print(dp[N][0][K] % mod)