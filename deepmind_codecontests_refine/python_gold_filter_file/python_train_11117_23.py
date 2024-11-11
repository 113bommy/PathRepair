R = lambda : input().split()

n, m = map(int, R())
a = [False] * n
b = [0] * n
for _ in range(m):
  p, s = R()
  p = int(p) - 1
  if s == 'AC':
    a[p] = True
  elif not a[p]:
    b[p] += 1
b =  [y for x, y in zip(a, b) if x]
print(len(b), sum(b))
