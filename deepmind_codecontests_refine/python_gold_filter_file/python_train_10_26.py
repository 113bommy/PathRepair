
q = int(input())
res = []

for a in range(q):

  l, r, d = map(int, input().split())

  k = l//d
  q = r//d + 1
  
  a = 1
  for a in range(1, k+1):
    x = d * a
    if l <= x <= r: continue
    else:
      res.append(x)
      a = 0
      break

  if a:
    for a in range(q, 2 * 10**9):
      x = d * a
      if l <= x <= r: continue
      else:
        res.append(x)
        break

for a in res: print(a)