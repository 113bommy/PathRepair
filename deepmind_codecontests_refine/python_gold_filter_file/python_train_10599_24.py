N, K = map(int, input().split())
A = [list(map(int, input().split())) for i in range(N)]
MOD = 10**9 + 7


def dot(M1, M2, mod=10**9+7):
  n = len(M1)
  res = [[0]*n for _ in range(n)]
  for i in range(n):
    for j in range(n):
      for k in range(n):
        res[i][j] += M1[i][k] * M2[k][j] % MOD
  
  return res


def power(M, k, mod=10**9+7):
  if k == 1:
    return M
  elif k%2 == 0:
    return power(dot(M, M, mod), k//2)
  else:
    return dot(M, power(dot(M, M, mod), k//2), mod)


trans = power(A, K) 

ans = 0
for t in trans:
  ans += sum(t)%MOD
  ans %= MOD

print(ans)