h,n=map(int,input().split())
dp=[10**10 for i in range(h+1)]
dp[0]=0
for i in range(n):
    x,y=map(int,input().split())
    for j in range(h+1):
        nj=min(h,j+x)
        dp[nj]=min(dp[nj],dp[j]+y)
print(dp[h])