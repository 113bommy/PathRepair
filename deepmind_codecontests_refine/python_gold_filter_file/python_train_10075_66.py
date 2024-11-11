n, s = map(int, input().split())
a = list(map(int, input().split()))
mod = 998244353

dp = [[0] * (s + 1) for _ in range(n + 1)]
dp[0][0] = 1

for i, e in enumerate(a, 1):
    for j in range(s + 1):
        dp[i][j] += 2 * dp[i-1][j]
        if j - e >= 0:
            dp[i][j] += dp[i-1][j-e]

        dp[i][j] %= mod

ans = dp[n][s]
print(ans)

