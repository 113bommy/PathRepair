N, S = map(int, input().split())
MOD = 998244353
A = list(map(int, input().split()))
dp = [0]*(S+1)
dp[0] = 1
for a in A:
    for s in reversed(range(S+1)):
        if s+a<=S: dp[s+a] += dp[s]
        dp[s] *= 2
        dp[s] %= MOD
print(dp[S]%MOD)