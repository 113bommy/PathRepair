import math,sys,bisect,heapq
from collections import defaultdict,Counter,deque
from itertools import groupby,accumulate
from functools import lru_cache
#sys.setrecursionlimit(200000000)
int1 = lambda x: int(x) - 1
#def input(): return sys.stdin.readline().strip()
input = iter(sys.stdin.buffer.read().decode().splitlines()).__next__
aj = lambda: list(map(int, input().split()))
def list3d(a, b, c, d): return [[[d] * c for j in range(b)] for i in range(a)]
#MOD = 1000000000 + 7
def Y(c):  print(["NO","YES"][c])
def y(c):  print(["no","yes"][c])
def Yy(c):  print(["No","Yes"][c])
    
G= defaultdict(list)


def addEdge(u,v):
    G[u].append(v)
    G[v].append(u)
    
def bfs(N):
    q = deque()
    vis = [False]*(N+1)
    q.append((1,1))
    vis[1] = True
    count = 0
    path = -1
    v = 0
    while q:
        path+=1
        for i in range(len(q)):
            p,r = q.popleft()
            z= G.get(p,[])
            # print(q,path)
            if len(z) == 1 and p != 1:
                v += path/r
            vis[p] = True
            for j in z:
                if not vis[j]:
                    if p == 1:
                        q.append((j,len(z)*r))
                    else:
                        q.append((j,(len(z)-1)*r))
    return v
            
    
N = int(input())
for i in range(N-1):
    u,v = aj()
    addEdge(u,v)
if N == 1:
    print(0)
    exit(0)
ans = bfs(N)
print(ans)
    