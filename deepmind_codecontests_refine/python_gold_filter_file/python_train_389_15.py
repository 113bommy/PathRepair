M=10**6+1
f=lambda p: exit(print(['pairwise','setwise','not'][p]+' coprime'))
n,*l=map(int,open(0).read().split())
from math import *
g,C=0,[0]*M
for x in l:
  g=gcd(g,x)
  C[x]=1
if g>1: f(2)
if any(sum(C[i::i])>1 for i in range(2,M)): f(1)
f(0)