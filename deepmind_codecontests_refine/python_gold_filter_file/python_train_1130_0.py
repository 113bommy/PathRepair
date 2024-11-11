import sys
input = sys.stdin.readline
import bisect

n = int(input())
X = list(map(int, input().split()))
l = int(input())
U = 17
dp = [[0]*n for _ in range(U+1)]
for i, x in enumerate(X):
  t = bisect.bisect_left(X, x+l)
  dp[0][i] = bisect.bisect_right(X, x+l) - 1
for k in range(U):
  for i in range(n):
    dp[k+1][i] = dp[k][dp[k][i]]
q = int(input())
for _ in range(q):
  a, b = map(int, input().split())
  a -= 1
  b -= 1
  if a > b:
    a, b = b, a
  res = 1
  for k in range(U, -1, -1):
    if dp[k][a] < b:
      a = dp[k][a]
      res += (1<<k)
    if a == b:
      break
  print(res)