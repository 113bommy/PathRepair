n,k = map(int, input().split())
h = list(map(int, input().split()))

dp = [0]*n
dp[1] = abs(h[1] - h[0])
for i in range(2,n):
  dp[i] = min([dp[i-j]+abs(h[i]-h[i-j]) for j in range(1,min(i,k)+1)])
  
print(dp[-1])