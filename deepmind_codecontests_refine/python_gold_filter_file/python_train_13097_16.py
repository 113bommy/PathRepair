n=int(input())
l=[list(map(int,input().split())) for _ in range(n)]
dp=[0]*3
for i in range(n):
    dp[0],dp[1],dp[2]=max(dp[1],dp[2])+l[i][0],max(dp[0],dp[2])+l[i][1],max(dp[0],dp[1])+l[i][2]
    #print(dp)
print(max(dp))