n,Ma,Mb=map(int,input().split())
inf=float("inf")
dp=[[[inf]*401 for _ in range(401)] for _ in range(n+1)]
dp[0][0][0]=0

l=[tuple(map(int,input().split())) for _ in range(n)]

for i in range(1,n+1):
    for j in range(401):
        for k in range(401):
            a,b,c=l[i-1]
            dp[i][j][k]=min(dp[i][j][k],dp[i-1][j][k])
            if j-a>=0 and k-b>=0:
                dp[i][j][k]=min(dp[i][j][k],dp[i-1][j-a][k-b]+c)

ans=inf
for i in range(1,1+min(400//Ma,400//Mb)):
    ans=min(ans,dp[n][Ma*i][Mb*i])

print(ans if ans!=inf else -1)