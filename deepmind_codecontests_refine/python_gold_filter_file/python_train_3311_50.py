R, G, B, n = map(int, input().split())
a, s = range(n+1), 0
for r in a:
  for g in a:
    b = (n-r*R-g*G)/B
    s += b.is_integer() and b >= 0
print(s)