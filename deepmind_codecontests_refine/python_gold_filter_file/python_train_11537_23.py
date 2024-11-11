import bisect
a, b, q = map(int, input().split())
inf = 10**18
s = [-inf] + [int(input()) for i in range(a)] + [inf]
t = [-inf] + [int(input()) for i in range(b)] + [inf]

for i in range(q):
  x = int(input())
  b, d = bisect.bisect_right(s, x), bisect.bisect_right(t, x)
  res = inf
  for S in [s[b-1], s[b]]:
    for T in [t[d-1], t[d]]:
      d1, d2 = abs(S-x) + abs(T-S), abs(T-x) + abs(S-T)
      res = min(d1, d2, res)
  print(res)
