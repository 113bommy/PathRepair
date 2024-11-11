n = int(input())

a = list(map(int, input().split()))

c = [0]*9
for i in a:
  t = i // 400
  if t < 8:
    c[t] = 1
  else:
    c[8] += 1
cmin = max(sum(c[:-1]), min(c[8], 1))
cmax = sum(c)
print(cmin, cmax)