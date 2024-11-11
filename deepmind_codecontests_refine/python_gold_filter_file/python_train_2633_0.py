import sys,os,io
input = sys.stdin.readline
#input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
n, m, k = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(m)]
A.sort(key = lambda x:x[0]+x[1])
table = [[0]*m for _ in range(n-k+1)]
for i in range(n-k+1): #i+1~i+k
  for j in range(m):
    lower = max(i+1, A[j][0])
    upper = min(i+k, A[j][1])
    table[i][j] = max(0,upper-lower+1)
from copy import deepcopy
cum1 = deepcopy(table)
cum2 = deepcopy(table)
ans = 0
for i in range(n-k+1):
  for j in range(1,m):
    cum1[i][j] += cum1[i][j-1]
for i in range(n-k+1):
  for j in range(m-2,-1,-1):
    cum2[i][j] += cum2[i][j+1]
# ans = max([cum1[i][-1] for i in range(n-k+1)])
ans = max([cum2[i][0] for i in range(n-k+1)])
for j in range(m-1):
  left = max([cum1[i][j] for i in range(n-k+1)])
  right = max([cum2[i][j+1] for i in range(n-k+1)])
  ans = max(ans, left+right)
print(ans)
