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

def main():
  n,q=ris()
  p=ris()
  
  adj=[[] for _ in range(n+1)]
  for u,up in enum(p):
    adj[up].append(2+u)
  
  a=[0]
  b=[0]*(n+1)
  c=[0]*(n+1)
  def dfs(u):
    b[u]=len(a)
    a.append(u)
    cc=0
    for v in adj[u]:
      cc+=dfs(v)
    c[u]=cc
    return 1+cc
  
  dfs(1)
  
  for _ in range(q):
    u,k=ris()
    k-=1
    if c[u]<k:
      print(-1)
    else:
      print(a[b[u]+k])

import threading
sys.setrecursionlimit(10**6)
threading.stack_size(10**8)
t=threading.Thread(target=main)
t.start()
t.join()
