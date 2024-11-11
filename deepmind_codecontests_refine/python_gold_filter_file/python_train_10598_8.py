R, D, x = map(int, input().split())
for _ in range(10):
  x = R*x - D
  print(x)