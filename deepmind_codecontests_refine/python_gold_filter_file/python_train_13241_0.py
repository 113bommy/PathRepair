nmax = 400
eratos = [0 for i in range(nmax+1)]
prime = []
cnt = 2
while True:
  while cnt <= nmax and eratos[cnt]:
    cnt += 1
  if cnt > nmax:
    break
  eratos[cnt] = 1
  prime.append(cnt)
  for i in range(cnt**2,nmax+1,cnt):
    eratos[i] = 1
from collections import defaultdict
import sys
input = sys.stdin.readline
n,k = map(int,input().split())
a = list(map(int,input().split()))
st = set()
for i in prime:
  if i**k > 10**5:
    break
  st.add(i**k)
dc = defaultdict(int)
ans = 0
for i in a:
  for j in st:
    while i%j == 0:
      i //= j
  dc[i] += 1
for i,v in dc.items():
  x = 1
  y = i
  if i == 1:
    ans += (v-1)*v//2
    continue
  if v == 0:
    continue
  for p in prime:
    cnt = 0
    while i%p == 0:
      cnt += 1
      i //= p
    if cnt:
      x *= p**(k-cnt)
  if i != 1:
    if k == 2:
      x *= i
    else:
      continue
  if x == y:
    ans += v*(v-1)//2
    continue
  if x in dc:
    ans += dc[x]*v
    dc[x] = 0
print(ans)