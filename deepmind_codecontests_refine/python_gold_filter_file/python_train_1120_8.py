n, K = [int(a) for a in input().split()]
s = [[int(a) for a in input().split()] for _ in range(K)]

MOD = 998244353

dp = [0] * (n + 1)
dp_sum = [0] * (n + 1)
dp[1] = 1

for i in range(1, n+1):
    for l, r in s:
        dp[i] += dp_sum[i-l if (i-l) > 0 else 0] - dp_sum[(i-r-1) if (i-r-1) > 0 else 0]
        dp_sum[i] = (dp[i] + dp_sum[i-1]) % MOD

print(dp[n] % MOD)