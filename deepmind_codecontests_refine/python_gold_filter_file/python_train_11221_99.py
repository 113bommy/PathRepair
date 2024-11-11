h, n = map(int, input().split())
dp = [10**10]*(h+10**4+1)
dp[0] = 0

for _ in range(n):
  a, b = map(int, input().split())
  for i in range(a, len(dp)):
    dp[i] = min(dp[i-a]+b, dp[i])

print(min(dp[h:]))