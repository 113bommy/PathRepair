n,k=map(int,input().split())
h=list(map(int,input().split()))

dp=[int(10e8)]*n
dp[0]=0
for i in range(1,n):
    for j in range(min(i,k)):
        dp[i]=min(dp[i],dp[i-j-1]+abs(h[i]-h[i-j-1]))

print(dp[n-1])
