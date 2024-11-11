import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**7)

class LCA:
    def __init__(self, edge, root):
        self.l = len(edge)
        self.stack = []
        self.stack.append((root, 0))
        self.vs = []
        self.depth = [0]*self.l
        self.firstVisited = [-1]*self.l
        while self.stack:
            v, d = self.stack[-1]
            if self.firstVisited[v] == -1:
                self.firstVisited[v] = len(self.vs)
            self.vs.append(v)
            self.depth[v] = d
            if edge[v]:
                self.stack.append((edge[v].pop(), d+1))
            else:
                self.stack.pop()
        
        self.n = len(self.vs)
        self.INF = (self.l, self.l)
        self.N0 = 1 << (self.n-1).bit_length()
        self.seg = [self.INF]*(self.N0 << 1)
        for i, v in enumerate(self.vs, self.N0):
            self.seg[i] = (self.depth[v], v)
        for i in range(self.N0-1, 0, -1):
            self.seg[i] = min(self.seg[2*i], self.seg[2*i+1])
    
    def _query(self, l, r):
        res = self.INF
        l += self.N0
        r += self.N0
        while l < r:
            if r & 1:
                res = min(res, self.seg[r-1])
            if l & 1:
                res = min(res, self.seg[l])
                l += 1
            l >>= 1
            r >>= 1
     
        return res

    def query(self, u, v):
        fu, fv = self.firstVisited[u], self.firstVisited[v]
        if fu > fv:
            fu, fv = fv, fu
        return self._query(fu, fv+1)[1]

n, q = map(int, input().split())
T = [[] for _ in range(n)]
for _ in range(n-1):
  a, b, c, d = map(int, input().split())
  a -= 1
  b -= 1
  T[a].append((b, c, d))
  T[b].append((a, c, d))
G = [[] for _ in range(n)]
edge = [[] for _ in range(n)]
stack = [(0, -1)]
while stack:
  v, par = stack.pop()
  for nv, c, d in T[v]:
    if nv == par:
      continue
    G[v].append((nv, c, d))
    edge[v].append(nv)
    stack.append((nv, v))

seg = LCA(edge, 0)
A = [0]*q
C = [[] for _ in range(n)]
num = [0]*n
cum = [0]*n
for i in range(q):
  x, y, u, v = map(int, input().split())
  u -= 1
  v -= 1
  a = seg.query(u, v)
  C[u].append((i, x, y, 1))
  C[v].append((i, x, y, 1))
  C[a].append((i, x, y, -2))
dist = 0
stack = [0]
def dfs(v):
  global dist
  for i, x, y, b in C[v]:
    A[i] += (dist + num[x]*y - cum[x]) * b
  for nv, c, d in G[v]:
    dist += d
    num[c] += 1
    cum[c] += d
    dfs(nv)
    dist -= d
    num[c] -= 1
    cum[c] -= d
dfs(0)
print(*A, sep="\n")