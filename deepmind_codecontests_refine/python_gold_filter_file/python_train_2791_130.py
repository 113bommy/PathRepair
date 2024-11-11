n, k = list(map(int,input().split()))
dp = [0]*n
a = list(map(int, input().split()))

for i in range(1, n):
  dp[i] =  min([dp[i-j-1]+abs(a[i]-a[i-j-1]) for j in range(min(k, i))])
print(dp[n-1])