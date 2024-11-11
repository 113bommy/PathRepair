r, D, x = map(int, input().split())

for i in range(1,11, 1):
  x = r*x - D
  print(x)