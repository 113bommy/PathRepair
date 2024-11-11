n,k =map(int ,input().split())
l=list(map(int ,input().split()))

dp=[float("inf")]*n
dp[0]=0
for i in range(n-1):
    for j in range(1,min(k+1,abs(n-i))):
        dp[i+j]=min(dp[i]+abs(l[i]-l[i+j]),dp[i+j])
print(dp[-1])