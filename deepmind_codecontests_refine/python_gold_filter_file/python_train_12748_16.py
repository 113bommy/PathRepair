n = int(input())
prev = 0
for i in range(1, n):
  prev = (prev + i) % n
  print(prev + 1, end=' ')