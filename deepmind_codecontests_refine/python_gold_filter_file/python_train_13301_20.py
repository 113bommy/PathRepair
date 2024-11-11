r,c,k=map(int,input().split())
a=[list(map(int,input().split())) for _ in range(k)]
dp=[[[0 for _ in range(c+1)]for _ in range(r+1)]for _ in range(5)]
for x,y,z in a:
    dp[4][x][y]=z
for i in range(1,r+1):
    for j in range(1,c+1):
        v=dp[4][i][j]
        dp[0][i][j]=max(dp[0][i][j-1],dp[0][i-1][j],dp[1][i-1][j],dp[2][i-1][j],dp[3][i-1][j])
        dp[1][i][j]=max(dp[1][i][j-1],dp[0][i][j-1]+v,dp[0][i-1][j]+v,dp[1][i-1][j]+v,dp[2][i-1][j]+v,dp[3][i-1][j]+v)
        dp[2][i][j]=max(dp[2][i][j-1],dp[1][i][j-1]+v)
        dp[3][i][j]=max(dp[3][i][j-1],dp[2][i][j-1]+v)
print(max([dp[i][r][c] for i in range(4)]))