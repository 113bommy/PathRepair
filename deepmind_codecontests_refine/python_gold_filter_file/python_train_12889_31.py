N, W = map(int, input().split())

INF = float("inf")
dp = [0] + [INF] * 10**5

for _ in range(N):
  w, v = map(int, input().split())
  for j in range(10**5, v-1, -1):
    dp[j] = min(dp[j], dp[j-v] + w)

for i, x in enumerate(dp):
  if x <= W:
    ans = i

print(ans)