import math

x = input().split()

def func(a, b):
  res = 0
  div = 1
  tmpb = b

  while a >= tmpb * 2:
    tmpb *= 2
    div *= 2
  while a >= b:
    a -= tmpb
    res += div
    while a < tmpb and tmpb % 2 == 0 and div > 1:
      tmpb //= 2
      div //= 2
  if a > 0:
    res += 1
  return '%d' % res

print(func(int(x[1]), int(x[0])))
