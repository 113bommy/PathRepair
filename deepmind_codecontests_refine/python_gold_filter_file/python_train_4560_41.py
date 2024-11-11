n, k = map(int, input().split())
A = sorted(list(map(int, input().split())))
F = sorted(list(map(int, input().split())))[::-1]
def is_time(x):
  c = 0
  for i in range(n):
    c += max(0, A[i] - x//F[i])
  if c <= k:
    return True
  return False
ng = -1
ok = 0
for i in range(n):
  ok = max(ok, A[i]*F[i])
while ok - ng > 1:
  m = (ng + ok)//2
  if is_time(m):
    ok = m
  else:
    ng = m
print(ok)