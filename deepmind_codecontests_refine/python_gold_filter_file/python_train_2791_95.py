n,k,*h=map(int,open(0).read().split())
dp=[0]+[10**18]*~-n
for i in range(1,n):
    for j in range(k):
        if i-k+j<0:continue
        dp[i]=min(dp[i],dp[i-k+j]+abs(h[i]-h[i-k+j]))
print(dp[-1])