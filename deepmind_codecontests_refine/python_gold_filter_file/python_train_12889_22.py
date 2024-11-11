IN=lambda:map(int,input().split())
N,W=IN()
INF=float("inf")
dp=[INF]*(1000*N)
dp.insert(0,0)
c=0
ans=0
for i in range(N):
    w,v=IN()
    for j in range((1000*N+1),-1,-1):
        if dp[j-v]!=INF:
            dp[j]=min(dp[j],dp[j-v]+w)
for i in range(1000*N+1):
    if dp[i]<=W:
        ans=i
print(ans)   