import sys,math,itertools
from collections import Counter,deque,defaultdict
from bisect import bisect_left,bisect_right 
from heapq import heappop,heappush,heapify
mod = 10**9+7
INF = float('inf')
def inp(): return int(sys.stdin.readline())
def inpl(): return list(map(int, sys.stdin.readline().split()))
def inpl_1(): return list(map(lambda x:int(x)-1, sys.stdin.readline().split()))
def inps(): return sys.stdin.readline()
def inpsl(x): tmp = sys.stdin.readline(); return list(tmp[:x])
def err(x): print(x); exit()

n,X = inpl(); X -= 1
g = [[] for _ in range(n)]
for _ in range(n-1):
    a,b = inpl_1()
    g[a].append(b)
    g[b].append(a)
dist = [-1]*n; dist[0] = 0
q = deque([0])
pa = -1
while q:
    u = q.popleft()
    for v in g[u]:
        if dist[v] != -1: continue
        if v == X: pa = u
        dist[v] = dist[u] + 1
        q.append(v)
dist2 = [-1]*n; dist2[X] = 0
q = deque([X])
while q:
    u = q.popleft()
    for v in g[u]:
        if dist2[v] != -1 or dist2[u]+1 >= dist[v]: 
            continue
        dist2[v] = dist2[u] + 1
        q.append(v)
# mx = max(dist2)
res = 0
for i in range(n):
    if dist2[i] >= 0:
        res = max(res, dist[i])
print(res*2)