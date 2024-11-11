import sys
import math

def calc():
  global ans, a, b

n, a, b = map(int, input().strip().split(' '))
n *= 6

if a*b >= n:
  print("%i %i %i" % (a*b, a, b))
  sys.exit(0)

m = int(math.sqrt(n)) + 10
ans = (10**15, 0, 0)

for i in range(m):
  k = max(b, n // (a + i))

  if k*(a + i) < n: 
    tmp = ( (k + 1)*(a + i), a + i, k + 1)
  else:
    tmp = ( (k + 0)*(a + i), a + i, k)

  if tmp < ans: ans = tmp

for i in range(m):
  k = max(a, n // (b + i))

  if k*(b + i) < n: 
    tmp = ( (k + 1)*(b + i), k + 1, b + i)
  else:
    tmp = ( (k + 0)*(b + i), k, b + i)

  if tmp < ans: ans = tmp

print("%i %i %i" % ans)

