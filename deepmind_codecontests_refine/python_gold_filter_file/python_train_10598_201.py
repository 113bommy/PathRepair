N,D,x = map(int, input().split())

for i in range(10):
  x = x * N - D
  print(x)
