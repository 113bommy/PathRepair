n, k = [int(a) for a in input().split()]
if k >= (n*(n-1)//2):
  print("no solution")
else:
  for x in range(n):
    print(0, x)
  