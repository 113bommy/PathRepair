import math
 
N = 1000001
 
spf = [*range(N)]
i = 2
while i * i < N:
  if spf[i] == i:
    for j in range(i * i, N, i):
      if spf[j] == j:
        spf[j] = i
  i += 1
  
r = 'pairwise'
 
input()
d = None
u = set()
for x in map(int, input().split()):
  d = math.gcd(d or x, x);
  s = set()
  while x > 1:
    p = spf[x]
    if p in u:
      r = 'setwise'
    s.add(p)
    x //= p
  u |= s
print(d > 1 and 'not' or r, 'coprime')
