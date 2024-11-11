a, b, x = map(int, input().split())
for i in range(10):
  x = a*x-b
  print(x)