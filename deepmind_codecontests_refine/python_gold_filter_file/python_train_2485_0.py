mod = 10**9+7
N,X,Y,Z = map(int, input().split())
num = 1<<(X+Y+Z-1)
ng = ((((1<<X)+1)<<Y)+1)<<(Z-1)

dp = [[0]*num for i in range(N+1)]
dp[0][0] = 1
for i in range(N):
    for j in range(1,11):
        for k in range(num):
            K = (k*2+1)<<(j-1)
            if K&ng != ng:
                K &= num-1
                dp[i+1][K] += dp[i][k]
                dp[i+1][K] %= mod

print((10**N%mod-sum(dp[N])%mod)%mod)