L, R = [int(n) for n in input().strip().split()]

if R - L > 0:
  print(2)
else:
  print(L)