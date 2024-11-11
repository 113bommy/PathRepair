import sys
input = sys.stdin.readline
H, N = map(int, input().split())
dp = [float("inf")] * (H + 1)
dp[H] = 0
for _ in range(N):
  a, b = map(int, input().split())
  for x in range(H, -1, -1):
    dp[max(0, x - a)] = min(dp[max(0, x - a)], dp[x] + b)
print(dp[0])