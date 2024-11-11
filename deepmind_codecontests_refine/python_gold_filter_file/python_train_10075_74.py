N, S = map(int, input().split())
A = list(map(int, input().split()))
MOD = 998244353

dp = [0] * (S + 1)
dp[0] = 1

for a in A:
    newDp = [d * 2 % MOD for d in dp]

    for s in range(S + 1):
        if s + a <= S:
            newDp[s + a] += dp[s]

    dp = newDp

print(dp[S] % MOD)
