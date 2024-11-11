n,s=map(int,input().split())
a=list(map(int,input().split()))
mod=998244353
dp=[[0 for i in range(s+1)] for j in range(n+1)]
dp[0][0]=1
for i in range(1,n+1):
    see=a[i-1]
    for j in range(s+1):
        dp[i][j]=dp[i-1][j]*2
        dp[i][j]%=mod
        if see>j:
            continue
        dp[i][j]+=dp[i-1][j-see]
        dp[i][j]%=mod

print(dp[-1][-1])
