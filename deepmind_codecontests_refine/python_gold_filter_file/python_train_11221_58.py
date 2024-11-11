H,N = map(int,input().split())
dp = [float('INF')]*(H+1)
dp[0]=0
for _ in range(N):
    a,b = map(int,input().split())
    for i in range(1,H+1):
        dp[i]=min(dp[max(i-a,0)]+b,dp[i])

print(dp[-1])