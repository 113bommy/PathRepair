MOD = 998244353

n, s = map(int, input().split())
As = list(map(int, input().split()))

dp = [0] * (s+2)

dp[0] = 1

for a in As:
    for i in range(s+1, -1, -1):
        if i - a < 0:continue
        dp[i] += dp[i-a] * (MOD+1) // 2
        dp[i] %= MOD

print(dp[s] * pow(2, n, MOD) % MOD)