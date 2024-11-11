import sys

readline = sys.stdin.buffer.readline

ns = lambda: readline().rstrip()
ni = lambda: int(readline().rstrip())
nm = lambda: map(int, readline().split())
nl = lambda: list(map(int, readline().split()))

def solve():
  s = list(ns())
  ls = len(s)
  lk = ni()
  dp = [[[0]*ls for _ in range(ls)] for i in range(2)]
  ans = 0
  for i in range(ls):
    dp[0][i][i] = 1
  for k in range(lk+1):
    v = k & 1
    for dis in range(1, ls):
      for i in range(ls - dis):
        j = i + dis
        dp[v][i][j] = 0
        if s[i] == s[j]:
          dp[v][i][j] = dp[v][i+1][j-1] + 2
        elif k:
          dp[v][i][j] = dp[v^1][i+1][j-1] + 2
        dp[v][i][j] = max(dp[v][i][j], dp[v][i+1][j], dp[v][i][j-1])
    ans = max(ans, dp[v][0][-1])

  print(ans)
  return

solve()