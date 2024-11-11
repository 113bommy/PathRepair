n,k=map(int,input().split())
h=list(map(int,input().split()))
INF=10**9+7
dp=[INF]*n
dp[0]=0

for i in range(1,n):
    s=min(k,i)
    for j in range(1,s+1):
        dp[i]=min(dp[i],abs(h[i]-h[i-j])+dp[i-j])
print(dp[n-1])