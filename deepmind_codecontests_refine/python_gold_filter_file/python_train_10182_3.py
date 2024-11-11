import sys
input = sys.stdin.readline

n = int(input())
A = tuple(map(int, input().split()))
B = tuple(map(int, input().split()))
def f(n):
  dp = list(range(n+1))
  for a, b in zip(A, B):
    if b <= a:
      continue
    for i in range(n+1):
      if i-a >= 0:
        dp[i] = max(dp[i], dp[i-a]+b)
  return dp[n]
m = f(n)
A, B = B, A
ans = f(m)
print(ans)