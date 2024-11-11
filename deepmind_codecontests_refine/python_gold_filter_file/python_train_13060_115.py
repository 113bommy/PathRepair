import math

def is_composite(n):
  for i in range(2, int(math.sqrt(n) + 1)):
    if n % i == 0:
      return True
  return False

n = int(input())
for i in range(4, n):
  if is_composite(i) and is_composite(n - i):
    print(i, n - i)
    break
