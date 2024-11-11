import sys
input = sys.stdin.readline

mod = 10**9+7
n, k = map(int, input().split())
A = tuple(tuple(map(int, input().split())) for _ in range(n))
def matmul(X, Y):
  Z = [[0]*n for _ in range(n)]
  for i in range(n):
    for j in range(n):
      for k in range(n):
        Z[i][j] += X[i][k] * Y[k][j]
        Z[i][j] %= mod
  return Z
  
def matpow(k):
  if k == 1:
    return A
  if k%2:
    return matmul(A, matpow(k-1))
  X = matpow(k//2)
  return matmul(X, X)

B = matpow(k)
ans = 0
for i in range(n):
  for j in range(n):
    ans += B[i][j]
    ans %= mod
print(ans)