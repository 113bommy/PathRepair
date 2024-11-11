n = int(input())
h = n//100
if 100*h <= n <= 105*h:
  print(1)
else:
  print(0)