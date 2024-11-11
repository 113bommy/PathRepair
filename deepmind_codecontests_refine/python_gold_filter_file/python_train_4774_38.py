n,ma,mb=map(int,input().split())
subs=[list(map(int,input().split())) for _ in range(n)]
infi=10**18
dp=[[[infi]*401 for _ in range(401)] for _ in range(n+1)]
dp[0][0][0]=0
for i in range(1,n+1):
    a,b,c=subs[i-1]
    for j in range(401):
        for k in range(401):
            if j+a<=400 and k+b<=400:
                dp[i][j+a][k+b]=min(dp[i][j+a][k+b],dp[i-1][j][k]+c)
            dp[i][j][k]=min(dp[i][j][k],dp[i-1][j][k])
ans=infi
for i in range(1,401):
    for j in range(1,401):
        if i%ma==0 and j%mb==0:
            if i//ma==j//mb:
                ans=min(ans,dp[n][i][j])
if ans==infi:
    ans=-1
print(ans)