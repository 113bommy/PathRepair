mod = 998244353

N, S, *A = map(int, open(0).read().split())

dp = [[0] * (S + 1) for _ in range(N + 1)]
dp[0][0] = 1

for i, a in enumerate(A):
    for j in range(S + 1):
        dp[i + 1][j] += 2 * dp[i][j]
        dp[i + 1][j] %= mod

        if j + a <= S:
            dp[i + 1][j + a] += dp[i][j]
            dp[i + 1][j + a] %= mod

print(dp[N][S])