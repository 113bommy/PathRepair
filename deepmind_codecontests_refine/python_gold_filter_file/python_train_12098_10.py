from math import sqrt

t = int(input())
for tt in range(t):
  n = int(input())
  x = set([0, 1, n])
  for i in range(1, int(sqrt(n)) + 1):
    #if n % i == 0: continue
    x.add(n // i)
    x.add(i % n)
  print(len(x))
  print(*sorted(x))
