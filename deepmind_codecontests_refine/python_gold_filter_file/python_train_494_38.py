from operator import itemgetter
from math import gcd
from collections import Counter

N = int(input())
mod = int(1e9+7)

zero = 0
P = {}
for i in range(N):
  a,b = list(map(int, input().split()))
  if a == 0 and b == 0:
    zero += 1
    continue
  g = gcd(a,b)
  a,b = a//g, b//g
  if b < 0:
    a,b = -a,-b
  if b == 0 and a < 0:
    a,b = -a,b  
  #rot90
  rot90 = a<=0
  if rot90:
    a,b = b,-a
  #add
  if not (abs(a),b) in P:
    P[(a,b)] = [0,0]
  if not rot90 :
    P[(a,b)][0] += 1
  else:
    P[(a,b)][1] += 1
    
ans = 1
for k,v in P.items():
  #print(k,v)
  s,t = v
  wk = 1 + pow(2,s,mod) - 1 + pow(2,t,mod) - 1
  ans *= wk
  ans %= mod
  
ans += zero

print((ans - 1) % mod)