R,C,K = map(int, input().split())

maze = [[0 for _ in range(C)] for _ in range(R)]
dp = [[[0 for _ in range(C+1)] for _ in range(R+1)] for _ in range(4)]
for i in range(K):
    r,c,v = map(int, input().split())
    r -=1
    c -= 1
    maze[r][c] = v

for i in range(R):
    for j in range(C):
        
        for k in range(2, -1, -1):
            dp[k+1][i][j] = max(dp[k+1][i][j], dp[k][i][j] + maze[i][j])

        for k in range(4):
            dp[0][i+1][j] = max(dp[0][i+1][j], dp[k][i][j])
            dp[k][i][j+1] = max(dp[k][i][j+1], dp[k][i][j])  

ans = 0

for k in range(4):
    ans = max(ans, dp[k][R-1][C-1])       

print(ans)