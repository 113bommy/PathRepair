GI = lambda: int(input()); GIS = lambda: map(int, input().split()); LGIS = lambda: list(GIS())

from math import sqrt

def main():
  p, y = GIS()

  for x in range(y, p, -1):
    for d in range(2, min(p, int(sqrt(x))) + 1):
      if not x % d:
        break
    else:
      return x

  return -1

print(main())
