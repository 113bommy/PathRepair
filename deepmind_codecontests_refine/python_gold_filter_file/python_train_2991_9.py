inf = 1234567890

class fenwick:
  def __init__(self, n):
    self.n = n
    self.f = [inf] * n

  def get(self, x):
    i = x
    ret = inf
    while i >= 0:
      ret = min(ret, self.f[i])
      i = (i & (i + 1)) - 1
    return ret

  def add(self, x, y):
    i = x
    while i < self.n:
      self.f[i] = min(self.f[i], y)
      i = i | (i + 1)


n = int(input())
s = list(map(int, input().split()))
c = list(map(int, input().split()))

map_trick = {}
for x in s:
  map_trick[x] = 0
  map_trick[x - 1] = 0

m = 0
keys = sorted(list(map_trick.keys()))
for key in keys:
  map_trick[key] = m
  m += 1

a = list(zip(s, c))

ans = inf

fen = fenwick(8000)

for i in range(n):
  for j in range(i + 1, n):
    size_first, cost_first = a[i]
    size_second, cost_second = a[j]
    if size_first < size_second:
      ans = min(ans, cost_first + cost_second + fen.get(map_trick[size_first] - 1)) 
  fen.add(map_trick[size_first], cost_first)

print(ans if ans < inf else -1)