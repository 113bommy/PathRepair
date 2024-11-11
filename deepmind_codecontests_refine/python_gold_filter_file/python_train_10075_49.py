N,S = map(int,input().split())
A = list(map(int,input().split()))
dp = [[0]*(S+2) for i in range(N+1)]
dp[0][0] = 1
mod = 998244353
for i,a in enumerate(A):
    for j in range(S+1):
        if j-a >= 0:
            dp[i+1][j] = (dp[i][j]*2+dp[i][j-a])%mod
        else:
            dp[i+1][j] = dp[i][j]*2%mod
print(dp[N][S])
