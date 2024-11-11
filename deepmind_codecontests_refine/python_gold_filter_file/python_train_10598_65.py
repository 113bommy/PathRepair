r, d, s = map(int, input().split())

for i in range(10):
  s = r * s - d
  print(s)
  