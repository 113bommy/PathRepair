def root(x):
  if F[x] < 0:
    return x
  else:
    F[x] = root(F[x])
    return F[x]

def unite(x, y):
  x = root(x)
  y = root(y)
  if x == y:
    return
  if x > y:
    x, y = y, x
  F[x] += F[y]
  F[y] = x

N, M = map(int, input().split())
F = [-1] * N

for m in range(M):
  a, b = map(int, input().split())
  unite(a - 1, b - 1)
ans = 0
for f in F:
  ans = min(ans, f)
print(-ans)
