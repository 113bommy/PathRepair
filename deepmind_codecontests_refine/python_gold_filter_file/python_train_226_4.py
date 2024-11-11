from collections import defaultdict,deque
import sys,heapq,bisect,math,itertools,string,queue,copy,time
sys.setrecursionlimit(10**8)
INF = float('inf')
mod = 10**9+7
eps = 10**-7
def inp(): return int(sys.stdin.readline())
def inpl(): return list(map(int, sys.stdin.readline().split()))
def inpl_str(): return list(sys.stdin.readline().split())

N,M = inpl()
aa = inpl()
bb = inpl()
aa.sort()
bb.sort()

a0 = aa[0]
ans = 10**10
for b in set(bb):
    x = (b-a0)%M
    aa_dush = sorted([(a+x)%M for a in aa])

    for a,b in zip(bb,aa_dush):
        if a != b:
            break
    else:
        ans = min(ans,x)

print(ans)
