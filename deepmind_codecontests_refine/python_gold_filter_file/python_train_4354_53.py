n,*a=map(int,open(0).read().split())
dp=[[0]*(n+1)for _ in range(n+1)]
for k in range(1,n+1):
    for i in range(n-k+1):
        j=i+k
        dp[i][j]=min(dp[i+1][j]-a[i],dp[i][j-1]-a[j-1])if(n-k)%2else max(dp[i+1][j]+a[i],dp[i][j-1]+a[j-1])
print(dp[0][n])