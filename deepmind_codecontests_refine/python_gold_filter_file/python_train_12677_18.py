from bisect import bisect

N, M, K = map(int, input().split())
A = [0]+list(map(int, input().split()))
B = list(map(int, input().split()))
R_B = [0]*(M+1)
i = 0
while i < M:
  R_B[i+1] = R_B[i]+B[i]
  i += 1 
ans = 0
i = 0
while i <= N and K >= A[i]:
  K -= A[i]
  idx = bisect(R_B, K)
  ans = max(ans, i+idx-1)
  i += 1
print(ans)

