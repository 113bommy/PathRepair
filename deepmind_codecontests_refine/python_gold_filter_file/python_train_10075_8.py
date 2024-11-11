n,s=map(int,input().split())
*A,=map(int,input().split())
mod=998244353
dp=[[0]*(s+1) for i in range(n+1)]
dp[0][0]=1
for i in range(n):
    for j in range(s+1):
        if A[i]+j<s+1:
            dp[i+1][j+A[i]]+=dp[i][j]
        dp[i+1][j]+=2*dp[i][j]
        dp[i+1][j]%=mod
print(dp[-1][-1])