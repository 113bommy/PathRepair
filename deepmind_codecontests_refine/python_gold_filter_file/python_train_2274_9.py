import functools
from fractions import gcd
N,K=map(int,input().split())
A=list(map(int,input().split()))


mod=functools.reduce(gcd,A)

tmp=0
if max(A)>=K and K%mod==0:
  print('POSSIBLE')
else:
  print('IMPOSSIBLE')
