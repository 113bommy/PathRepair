n,s=map(int,input().split())
a=list(map(int,input().split()))
mod=998244353
dp=[[0]*(s+1) for _ in range(n+1)]
dp[0][0]=1
for i in range(1,n+1):
    for j in range(s+1):
        if j+a[i-1]<=s:
            dp[i][j+a[i-1]]+=dp[i-1][j]
            dp[i][j+a[i-1]]%=mod
        dp[i][j]+=dp[i-1][j]*2
        dp[i][j]%=mod
print(dp[n][s])