from heapq import heappush, heappop
class MinCostFlow:
    INF = 10**18

    def __init__(self, N):
        self.N = N
        self.G = [[] for i in range(N)]

    def add_edge(self, fr, to, cap, cost):
        forward = [to, cap, cost, None]
        backward = forward[3] = [fr, 0, -cost, forward]
        self.G[fr].append(forward)
        self.G[to].append(backward)

    def flow(self, s, t, f):
        N = self.N; G = self.G
        INF = MinCostFlow.INF

        res = 0
        H = [0]*N
        prv_v = [0]*N
        prv_e = [None]*N

        d0 = [INF]*N
        dist = [INF]*N

        while f:
            dist[:] = d0
            dist[s] = 0
            que = [(0, s)]

            while que:
                c, v = heappop(que)
                if dist[v] < c:
                    continue
                r0 = dist[v] + H[v]
                for e in G[v]:
                    w, cap, cost, _ = e
                    if cap > 0 and r0 + cost - H[w] < dist[w]:
                        dist[w] = r = r0 + cost - H[w]
                        prv_v[w] = v; prv_e[w] = e
                        heappush(que, (r, w))
            if dist[t] == INF:
                return None

            for i in range(N):
                H[i] += dist[i]

            d = f; v = t
            while v != s:
                d = min(d, prv_e[v][1])
                v = prv_v[v]
            f -= d
            res += d * H[t]
            v = t
            while v != s:
                e = prv_e[v]
                e[1] -= d
                e[3][1] += d
                v = prv_v[v]
        return res

class UnionFindVerSize():
    def __init__(self, N):
        self._parent = [n for n in range(0, N)]
        self._size = [1] * N
        self.group = N

    def find_root(self, x):
        if self._parent[x] == x: return x
        self._parent[x] = self.find_root(self._parent[x])
        stack = [x]
        while self._parent[stack[-1]]!=stack[-1]:
            stack.append(self._parent[stack[-1]])
        for v in stack:
            self._parent[v] = stack[-1]
        return self._parent[x]

    def unite(self, x, y):
        gx = self.find_root(x)
        gy = self.find_root(y)
        if gx == gy: return

        self.group -= 1

        if self._size[gx] < self._size[gy]:
            self._parent[gx] = gy
            self._size[gy] += self._size[gx]
        else:
            self._parent[gy] = gx
            self._size[gx] += self._size[gy]

    def get_size(self, x):
        return self._size[self.find_root(x)]

    def is_same_group(self, x, y):
        return self.find_root(x) == self.find_root(y)

n,m = map(int,input().split())

G = MinCostFlow(n+2)
coef = [0 for i in range(n)]
edge = []
for _ in range(m):
    x,y,b = map(int,input().split())
    G.add_edge(y,x,10**18,-1)
    coef[x-1] += b
    coef[y-1] -= b
    edge.append((x,y))

s = 0
for i in range(n):
    if coef[i]<0:
        G.add_edge(0,i+1,-coef[i],0)
        s -= coef[i]
    elif coef[i]>0:
        G.add_edge(i+1,n+1,coef[i],0)

#G.add_edge(0,n+1,10**18,0)

f = G.flow(0,n+1,s)
#print(-f)

Edge = [[] for i in range(n)]
use = [False]*m
uf = UnionFindVerSize(n)
for i in range(m):
    u,v = edge[i]
    for e in G.G[u]:
        to = e[0]
        if to==v and e[1]:
            Edge[v-1].append((u-1,1))
            Edge[u-1].append((v-1,-1))
            use[i] = True
            uf.unite(u-1,v-1)


edge = [(edge[i][0],edge[i][1]) for i in range(m) if not use[i]]
for u,v in edge:
    if not uf.is_same_group(u-1,v-1):
        Edge[v-1].append((u-1,1))
        Edge[u-1].append((v-1,-1))
        uf.unite(u-1,v-1)

used_1 = [False]*n
used_2 = [False]*n
lazy = [0 for i in range(n)]
a = [0 for i in range(n)]
def dfs(v,pv):
    lazy[v] = min(lazy[v],a[v])
    for nv,c in Edge[v]:
        if not used_1[nv]:
            used_1[nv] = True
            a[nv] = a[v] + c
            dfs(nv,v)
            lazy[v] = min(lazy[v],lazy[nv])

def add(v,pv,ff):
    a[v] += ff
    for nv,c in Edge[v]:
        if not used_2[nv]:
            used_2[nv] = True
            add(nv,v,ff)

for i in range(n):
    if not used_1[i]:
        used_1[i] = True
        dfs(i,-1)
        used_2[i] = True
        add(i,-1,-lazy[i]+1)
        #print(used_1)
        #print(lazy)

print(*a)
