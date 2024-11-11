from math import log10 as log2

N, K = map(int, input().split())
A = [int(i) for i in input().split()]

mod = 10 ** 9 + 7

p = []
m = []
for a in A :
  if a > 0 :
    p.append(a)
  elif a < 0 :
    m.append(-a)
    
p.sort(reverse=True)
m.sort(reverse=True)
pl = [0]
ml = [0]

for i in range(len(p)) :
  pl.append(log2(p[i]))
for i in range(len(m)) :
  ml.append(log2(m[i]))
for i in range(1, len(pl)) :
  pl[i] += pl[i - 1]
for i in range(1, len(ml)) :
  ml[i] += ml[i - 1]

Mi = -1
Mv = 0
for i in range(0, len(ml), 2) :
  j = K - i
  if len(pl) <= j or j < 0 : continue
  if ml[i] + pl[j] > Mv :
    Mi, Mv = i, ml[i] + pl[j]

if Mi != -1 :
  ret = 1
  for i in range(K - Mi) :
    ret *= p[i]
    ret %= mod
  for i in range(Mi) :
    ret *= m[i]
    ret %= mod
else :
  x = [abs(a) for a in A]
  x.sort()
  ret = 1
  for i in range(K) :
    ret *= x[i]
    ret %= mod
  ret = -ret % mod
  
print(ret)