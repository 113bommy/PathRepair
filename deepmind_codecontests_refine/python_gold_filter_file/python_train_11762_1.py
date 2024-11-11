import math
a, b, c = map(int, input().split())
for k in range(60):
  t = math.ceil((k * (a + b) - c) / 60)
  if t <= (k * (a + b) + a - c) / 60:
    print(t * 60 + c)
    break
else:
  print(-1)

