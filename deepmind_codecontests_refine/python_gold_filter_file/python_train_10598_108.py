r,D,xi = map(int, input().split())
for i in range(10):
  xi = r * xi - D
  print(xi)