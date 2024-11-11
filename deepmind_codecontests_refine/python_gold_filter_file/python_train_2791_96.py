n,k  = map(int, input().split())
h = list(map(int, input().split()))

dp = [0] * n
for i in range(1, n):
  start = max(0, i - k)
  dp[i] = min([dp[j] + abs(h[j]-h[i]) for j in range(start, i)])  
  
print(dp[n-1])