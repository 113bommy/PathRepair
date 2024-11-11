import sys
MAX_INT = int(10e12)
MIN_INT = -MAX_INT
mod = 1000000007
sys.setrecursionlimit(1000000)
def IL(): return list(map(int,input().split()))
def SL(): return input().split()
def I(): return int(sys.stdin.readline())
def S(): return input()

N = I()
a = IL()

dp = [[0]*(N+1) for i in range(N+1)]
data = [[0]*(N+1) for i in range(N+1)] # data[i][j] = sum(a[i:j])
for i in range(N):
  data[i][i+1] = a[i]
for i in range(N+1):
  for j in range(N+1):
    if i+j <= N:
      data[j][i+j] = sum(a[j:i+j])
    else:
      break

for i in range(2,N+1):
  for j in range(N+1):
    if i+j <= N:
      tmp = MAX_INT
      for k in range(1,i):
        tmp = min(tmp,dp[j][k+j] + dp[k+j][i+j])
      dp[j][i+j] = tmp + data[j][i+j]
    else:
      break

#print(data)
#print(dp)
print(dp[0][N])
