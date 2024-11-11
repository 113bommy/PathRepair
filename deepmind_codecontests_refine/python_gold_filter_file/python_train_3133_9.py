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

s=rl()
t=rl()
n=max(len(s),len(t))
s=('.'*n+s)[-n:]
t=('.'*n+t)[-n:]
ans=k=0
for i in range(n):
  if s[i]=='.' or t[i]=='.':
    ans+=1
  elif s[i]==t[i]:
    k+=2
  else:
    ans+=2+k
    k=0
print(ans)
