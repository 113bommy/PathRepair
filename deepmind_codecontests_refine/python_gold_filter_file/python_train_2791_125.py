n,k=map(int,input().split())
h=list(map(int,input().split()))
INF = 10**4+1
dp = [INF]*n
dp[0]=0
for i in range(1,n):
  dp[i] = min([dp[j] + abs(h[j]-h[i]) for j in range(max(0, i-k),i)])
print(dp[n-1])