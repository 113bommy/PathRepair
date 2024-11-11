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

def solve(s):
  a=[]
  n=len(s)
  i=0
  while i<n:
    dot=s.find('.',i)
    if dot==i or dot==-1 or dot-i>8 or n-dot==1:
      return []
    j=s.find('.',dot+1)
    if j==-1:
      if n-dot>4:
        return []
      j=n
    elif j-dot<=2:
      return []
    elif j-dot>4:
      j=dot+4
    else:
      j-=1
    a.append((i,j))
    i=j
  return a

s=rl()
n=len(s)
a=solve(s)
if not a:
  print('NO')
else:
  print('YES')
  ans=[]
  for i,j in a:
    ans.append(s[i:j])
  print('\n'.join(ans))
