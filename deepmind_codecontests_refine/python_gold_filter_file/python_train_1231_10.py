n, h = map(int, input().split())

a = []
b = []

for i in range(n):
  x, y = map(int, input().split())
  a.append(x)
  b.append(y)

max_a = max(a)

ans = 0
for x in reversed(sorted(filter(lambda x: x >= max_a, b))):
  h -= x
  ans += 1
  if h <= 0: break

ans += max(0, (h + max_a - 1) // max_a)
print(ans)

