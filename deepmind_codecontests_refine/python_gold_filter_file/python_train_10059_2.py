s=input()

n=len(s)
dp=[[0,0,0] for i in range(n)]
if s[n-1]=="a":
    dp[n-1][0]=1
    dp[n-1][1]=0
    dp[n-1][2]=1
if s[n-1]=="b":
    dp[n-1][0]=0
    dp[n-1][1]=1
    dp[n-1][2]=0
for i in range(n-2,-1,-1):
    if s[i]=="a":
        dp[i][0]=max(dp[i+1][0]+1,dp[i+1][1]+1)
        dp[i][1]=max(dp[i+1][2],dp[i+1][1])
        dp[i][2]=dp[i+1][2]+1
    else:
        # dp[i][j][0]=max(dp[i+1][j][0],dp[i+1][j][1]+1)
        # dp[i][j][1]=max(dp[i+1][j][2],dp[i+1][j][1])
        # dp[i][j][2]=dp[i][j][2]+1
        dp[i][0]=max(dp[i+1][0],dp[i+1][1])
        dp[i][1]=max(dp[i+1][2]+1,dp[i+1][1]+1)
        dp[i][2]=dp[i+1][2]
print(max(dp[0][0],dp[0][1],dp[0][2]))