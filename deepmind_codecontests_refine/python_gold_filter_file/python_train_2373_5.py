x = int(input())

a = x // 100
n = x % 100

if a*5 < n:
  print(0)
else:
  print(1)