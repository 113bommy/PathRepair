N, S = map(int, input().split())
A = list(map(int, input().split()))
MOD = 998244353

dp = [[0 for _ in range(S+1)] for __ in range(N+1)]
dp[0][0] = 1

for i in range(N):
    for j in range(S+1):
        dp[i+1][j] += 2 * dp[i][j]
        dp[i+1][j] %= MOD
        if j+A[i] <= S:
            dp[i+1][j+A[i]] += dp[i][j]
            dp[i+1][j+A[i]] %= MOD

print(dp[N][S])