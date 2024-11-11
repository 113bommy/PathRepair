import sys
input = sys.stdin.readline

s = input().rstrip()
t = input().rstrip()
ls = len(s)
lt = len(t)
dp = [[0]*(lt+1) for _ in range(ls+1)]
for i in range(ls):
  for j in range(lt):
    if s[i] == t[j]:
      dp[i+1][j+1] = dp[i][j] + 1
    else:
      dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1])
ans = ""
while ls > 0 and lt > 0:
  if dp[ls][lt] == dp[ls-1][lt]:
    ls -= 1
  elif dp[ls][lt] == dp[ls][lt-1]:
    lt -= 1
  else:
    ans = s[ls-1] + ans
    ls -= 1
    lt -= 1
print(ans)