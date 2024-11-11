from math import ceil
n,jump,count=map(int,input().split())
a=[0]+list(map(int,input().split()))
dp=[[-1]*(count+1) for i in range(n+1) ]
dp[0][0]=0
for i in range(n):
    for j in range(count):
        if dp[i][j]>=0:
            for k in range(1,min(jump,n-i)+1):
                dp[i+k][j+1]=max(dp[i+k][j+1],dp[i][j]+a[i+k])
ans=0
for i in range(n-jump+1,n+1):
    ans=max(ans,dp[i][count])
if n//jump>count:
    print(-1)
else:
    print(ans)