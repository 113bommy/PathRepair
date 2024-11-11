import sys
sys.setrecursionlimit(10**8)
input = sys.stdin.readline
N = int(input())
C = list(map(int,input().split()))
AB = [tuple(map(int,input().split())) for i in range(N-1)]

es = [[] for _ in range(N)]
for a,b in AB:
    a,b = a-1,b-1
    es[a].append(b)
    es[b].append(a)
cs = [[] for _ in range(N)]
for i,c in enumerate(C):
    cs[c-1].append(i)

tin = [-1]*N
tout = [-1]*N
k = 0
def dfs(v,p=-1):
    global k
    tin[v] = k
    k += 1
    for to in es[v]:
        if to==p: continue
        dfs(to,v)
    tout[v] = k
dfs(0)

class BinaryIndexedTree:
    def __init__(self,size):
        self.N = size
        self.bit = [0]*(size+1)
    def add(self,x,w): # 0-indexed
        x += 1
        while x <= self.N:
            self.bit[x] += w
            x += (x & -x)
    def _sum(self,x): # 1-indexed
        ret = 0
        while x > 0:
            ret += self.bit[x]
            x -= (x & -x)
        return ret
    def sum(self,l,r): # [l,r)
        return self._sum(r) - self._sum(l)
    def __str__(self): # for debug
        arr = [self.sum(i,i+1) for i in range(self.N)]
        return str(arr)
bit = BinaryIndexedTree(N)
for i in range(N):
    bit.add(i,1)

whole = N*(N+1)//2
anss = []
for i in range(N):
    ans = whole
    cs[i].sort(key=lambda x: -tin[x])
    history = []
    for v in cs[i]:
        cnt = 1
        for to in es[v]:
            if tin[to] < tin[v]: continue
            num = bit.sum(tin[to], tout[to])
            ans -= num*(num+1)//2
            cnt += num
        bit.add(tin[v], -cnt)
        history.append((tin[v], cnt))
    pn = bit.sum(0,N)
    ans -= pn*(pn+1)//2
    for a,b in history:
        bit.add(a,b)
    anss.append(ans)
print(*anss, sep='\n')