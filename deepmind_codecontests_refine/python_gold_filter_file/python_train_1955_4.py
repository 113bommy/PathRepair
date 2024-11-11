import sys
input = sys.stdin.readline
n = int(input())
a = [input().rstrip() for i in range(n)]
ls0 = []
ls25 = []
for i in range(n):
  s = a[i]
  l = len(s)
  if "." in s:
    pt = s.index(".")
    ls0.append(l-pt-1)
    x = s[:pt]+s[pt+1:]
  else:
    ls0.append(0)
    x = s
  ix = int(x)
  c2 = 0
  while ix%2 == 0:
    c2 += 1
    ix //= 2
  c5 = 0
  ix = int(x)
  while ix%5 == 0:
    c5 += 1
    ix //= 5
  ls25.append((c2-ls0[-1],c5-ls0[-1]))
ls25.sort()
ls2 = list(zip(*ls25))[0]
from collections import defaultdict
import bisect
dic5 = defaultdict(int)
ans = 0
for i in range(n)[::-1]:
  if ls2[i] < 0:
    break
  ind = bisect.bisect_left(ls2,-ls2[i])
  if i == n-1:
    for j in range(ind,n-1):
      dic5[ls25[j][1]] += 1
    ptr = ind
  else:
    for j in range(ptr,ind):
      dic5[ls25[j][1]] -= 1
    dic5[ls25[i][1]] -= 1
    ptr = ind
  for v,num in dic5.items():
    if v+ls25[i][1] >= 0:
      ans += num
print(ans)