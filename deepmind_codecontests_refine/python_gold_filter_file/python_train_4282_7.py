import math
import sys
input = sys.stdin.readline
n, s = map(int, input().split())
v = list(map(int, input().split()))
tot, mn = sum(v), min(v)
if tot < s:
  ans = -1
else:
  res = 0
  for i in range(n):
    if v[i] > mn:
      res += v[i] - mn
      v[i] -= mn
  if res >= s:
    ans = mn
  else:
    s -= res
    ans = mn - math.ceil(s / n)
print(ans)