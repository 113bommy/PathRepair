import re
import sys
exit=sys.exit
from bisect import bisect_left as bsl,bisect_right as bsr
from collections import Counter,defaultdict as ddict,deque
from functools import lru_cache
cache=lru_cache(None)
from heapq import *
from itertools import *
from math import inf
from pprint import pprint as pp
enum=enumerate
ri=lambda:int(rln())
ris=lambda:list(map(int,rfs()))
rln=sys.stdin.readline
rl=lambda:rln().rstrip('\n')
rfs=lambda:rln().split()
mod=1000000007
d4=[(0,-1),(1,0),(0,1),(-1,0)]
d8=[(-1,-1),(0,-1),(1,-1),(-1,0),(1,0),(-1,1),(0,1),(1,1)]
########################################################################

def solve(n,a,b):
  k=c=0
  for i in range(n):
    m=b[i]-a[i]
    if m<0:
      return 0
    if m>0:
      if c and m!=k:
        return 0
      c=1
    k=m
  return 1

t=ri()
for _ in range(t):
  n=ri()
  a=ris()
  b=ris()
  if solve(n,a,b):
    print('YES')
  else:
    print('NO')
