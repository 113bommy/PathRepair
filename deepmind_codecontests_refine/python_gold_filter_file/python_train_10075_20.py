n,s = map(int, input().split())
a = list(map(int, input().split()))

MOD = 998244353

dp = [[0]*(s+1) for i in range(n+1)] #動的計画法を用いる
dp[0][0] = 1

for i in range(n):
    for ss in range(s+1):
        if(ss >= a[i]):
            dp[i+1][ss] = (dp[i][ss]*2 + dp[i][ss-a[i]])%MOD #非常に大きな数になると考えられるため先にMOD計算を行う
        else:
            dp[i+1][ss] = dp[i][ss]*2 % MOD

print(dp[n][s])