import sys

n, m = map(int, input().split())
INF = 10 ** 9
dp = [INF] * (1 << n)
dp[0] = 0
bits = [0] + [1 << i for i in range(n)]
get_bits = bits.__getitem__

for _ in [0] * m:
  a, b = map(int, sys.stdin.readline().split())
  s = sum(map(get_bits, map(int, sys.stdin.readline().split())))
  for t in range(1 << n):
    if (dp[t] == -1):
      continue
    dp[t | s] = min(dp[t | s], dp[t] + a)

print(dp[-1] if dp[-1] != INF else -1)
