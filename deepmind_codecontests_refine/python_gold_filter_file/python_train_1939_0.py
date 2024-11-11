n = int(input())
n = 2*n
w = [int(i) for i in input().split()]
w.sort()

import math
res = math.inf
for x in range(n):
  for y in range(x+1, n):
      wc = w[:]
      wc.pop(y); wc.pop(x)
      # print(wc)
      s = 0
      for i in range(0, n-3, 2):
        s += wc[i+1]-wc[i]
      res = min(s, res)
print(res)