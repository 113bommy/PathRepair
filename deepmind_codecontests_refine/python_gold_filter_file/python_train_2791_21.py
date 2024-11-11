n,k=map(int,input().split())
h=list(map(int,input().split()))

dp=[1000000000]*n
dp[0]=0
for i in range (1,n):
    for j in range(max(i-k,0),i):
        dp[i]=min(dp[i],dp[j]+abs(h[i]-h[j]))
print(dp[n-1])