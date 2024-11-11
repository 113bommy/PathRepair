import sys
input = sys.stdin.readline
n, m = map(int, input().split())

dp = [float('inf')]*(1<<n)
dp[0] = 0

for i in range(m):
  a, b = map(int, input().split())
  c = 0
  for j in list(map(int, input().split())):
    c += 1<<(j-1)
  
  for k in range(1<<n):
    dp[k|c] = min(dp[k|c], dp[k]+a)
    
if dp[-1] == float('inf'):
  print(-1)
else:
  print(dp[-1])