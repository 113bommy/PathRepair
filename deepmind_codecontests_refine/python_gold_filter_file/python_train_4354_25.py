n = int(input())
a = list(map(int, input().split()))
dp = [[None]*n for _ in range(n)]
for d in range(n):
  for l in range(n-d):
    r = l + d
    if d:
      dp[l][r] = max(a[l] - dp[l+1][r], a[r] - dp[l][r-1])
    else:
      dp[l][r] = a[l]
print(dp[0][n-1])