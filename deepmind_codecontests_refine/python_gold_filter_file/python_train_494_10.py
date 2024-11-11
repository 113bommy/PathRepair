from collections import defaultdict
from math import gcd
N,*L = map(int, open(0).read().split())
dic = defaultdict(int)
ans = 0
MOD = 10**9+7
S = set()
for a,b in zip(*[iter(L)]*2):
  if a==0 and b==0:
    ans += 1
    continue
  g = gcd(a,b)
  if b>0:
    dic[(a//g,b//g)] += 1
    S.add((a//g,b//g))
  elif b<0:
    dic[(-a//g,-b//g)] += 1
    S.add((-a//g,-b//g))
  else:
    dic[(1,0)] += 1
    S.add((1,0))
m = 1
for a,b in S:
  if a<=0:
    if dic[(b,-a)]==0:
      m *= pow(2,dic[(a,b)],MOD)
      m %= MOD
      continue
  else:
    if dic[(-b,a)]==0:
      m *= pow(2,dic[(a,b)],MOD)
      m %= MOD
      continue
    c = pow(2,dic[(a,b)],MOD)+pow(2,dic[(-b,a)],MOD)-1
    m *= c
    m %= MOD
ans = (m-1+ans)%MOD
print(ans)