N = int(input()) 
A = list(map(int,input().split()))

CSUM = [0 for _ in range(N)]
CSUM[0] = A[0]
for i in range(1,N):
  CSUM[i] = CSUM[i-1] + A[i]
#print(CSUM)
def csum(i,j):
  if i == 0:
    return CSUM[j]
  else:
    return CSUM[j]-CSUM[i-1]

dp = [[0 for _ in range(N)] for _ in range(N)]

for k in range(1,N):
  for i in range(N-k):
    j = i+k
    tmp = 10**18
    for l in range(i,j):
      tmp = min(tmp,dp[i][l]+dp[l+1][j] + csum(i,j))
    dp[i][j] = tmp

print(dp[0][N-1])
#print(dp)
