n,k=map(int,input().split())
h=list(map(int,input().split()))
dp=[0]*n
for i in range(1,n):
    dp[i]=min([dp[j]+abs(h[i]-h[j]) for j in range(max(i-k,0),i)])
print(dp[n-1])
