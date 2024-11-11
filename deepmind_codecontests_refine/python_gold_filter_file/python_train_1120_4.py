N,K = map(int,input().split())
S = [tuple(map(int,input().split())) for _ in range(K)]
MOD=998244353
dp=[0]*N
dp[0]=1
for i in range(N-1):
    x = dp[i]
    dp[0]=0
    for k in range(K):
        l,r = S[k]
        if i+l < N:
            dp[i+l]+=x
            dp[i+l]%=MOD
        if i+r+1 < N:
            dp[i+r+1]-=x
            dp[i+r+1]%=MOD
    dp[i+1]+=dp[i]
    dp[i+1]%=MOD
print(dp[-1]%MOD)