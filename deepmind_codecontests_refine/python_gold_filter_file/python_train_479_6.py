from collections import Counter
def lInt(d = None): return map(int, input().split(d))

t = 0; p = 0
f = Counter()
n, *_ = lInt()

for i, v in enumerate(lInt()):
  x = f[v-1]
  y = f[v]
  z = f[v+1]
  m = i-x-y-z
  a = p+(v-1)*x+v*y+(v+1)*z
  t += a+m*v
  p -= v
  f[v] += 1
print(t)
