import sys,os,io
input = sys.stdin.readline
#input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
T = int(input())
ans = [0]*T
from collections import Counter
for t in range(T):
  n = int(input())
  A = list(map(int,input().split()))
  c = Counter(A)
  dp = [[float('inf')]*401 for _ in range(201)]
  dp[0] = [0]*201
  for i in range(1,201):
    if c[i]==0:
      dp[i] = dp[i-1]
      continue
    cnt = 0
    for p in range(1,c[i]+1):
      cnt += abs(p-i)
    for j in range(c[i],401):
      dp[i][j] = min(dp[i-1][:j-c[i]+1])+cnt
      cnt -= abs(i-(j-c[i]+1))
      cnt += abs(j+1-i)
  ans[t] = min(dp[200])
print(*ans, sep='\n')