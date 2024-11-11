import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,copy,functools
# import time,random,resource

sys.setrecursionlimit(10**7)
inf = 10**20
eps = 1.0 / 10**10
mod = 10**9+7
mod2 = 998244353
dd = [(-1,0),(0,1),(1,0),(0,-1)]
ddn = [(-1,0),(-1,1),(0,1),(1,1),(1,0),(1,-1),(0,-1),(-1,-1)]

def LI(): return list(map(int, sys.stdin.readline().split()))
def LLI(): return [list(map(int, l.split())) for l in sys.stdin.readlines()]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def S(): return input()
def pf(s): return print(s, flush=True)
def pe(s): return print(str(s), file=sys.stderr)
def JA(a, sep): return sep.join(map(str, a))
def JAA(a, s, t): return s.join(t.join(map(str, b)) for b in a)
def IF(c, t, f): return t if c else f


class Edge():
    def __init__(self,t,f,r,ca,co):
        self.to = t
        self.fron = f
        self.rev = r
        self.cap = ca
        self.cost = co

class MinCostFlow():
    size = 0
    graph = []

    def __init__(self, s):
        self.size = s
        self.graph = [[] for _ in range(s)]

    def add_edge(self, f, t, ca, co):
        self.graph[f].append(Edge(t, f, len(self.graph[t]), ca, co))
        self.graph[t].append(Edge(f, t, len(self.graph[f])-1, 0, -co))

    def min_path(self, s, t):
        dist = [inf] * self.size
        route = [None] * self.size
        que = collections.deque()
        inq = [False] * self.size
        dist[s] = 0
        que.append(s)
        inq[s] = True
        while que:
            u = que.popleft()
            inq[u] = False
            for e in self.graph[u]:
                if e.cap == 0:
                    continue
                v = e.to
                if dist[v] > dist[u] + e.cost:
                    dist[v] = dist[u] + e.cost
                    route[v] = e
                    if not inq[v]:
                        que.append(v)
                        inq[v] = True

        if dist[t] == inf:
            return inf, 0

        # 途中終了する場合
        if dist[t] > 0:
            return dist[t], -1

        flow = inf
        v = t
        while v != s:
            e = route[v]
            if flow > e.cap:
                flow = e.cap
            v = e.fron

        c = 0
        v = t
        while v != s:
            e = route[v]
            e.cap -= flow
            self.graph[e.to][e.rev].cap += flow
            c += e.cost * flow
            v = e.fron

        return dist[t], flow

    def calc_min_cost_flow(self, s, t, flow):
        total_cost = 0
        while flow > 0:
            c,f = self.min_path(s, t)
            if f == 0:
                return inf
            if f < 0:
                return total_cost
            f = min(flow, f)
            total_cost += c * f
            flow -= f

        return total_cost


def main():
    n,k = LI()
    aa = [LI() for _ in range(n)]

    ri = [n*n+i for i in range(n)]
    ci = [n*n+n+i for i in range(n)]
    s = n*n+n*2
    t = n*n+n*2+1
    mcf = MinCostFlow(n*n+n*2+2)
    for i in range(n):
        mcf.add_edge(s, ri[i], k, 0)
        mcf.add_edge(ci[i], t, k, 0)

    for r in range(n):
        for c in range(n):
            rc = r*n+c
            mcf.add_edge(ri[r], rc, 1, -aa[r][c])
            mcf.add_edge(rc, ci[c], 1, 0)

    res = -mcf.calc_min_cost_flow(s,t,n*k)
    ra = [['.']*n for _ in range(n)]
    for r in range(n):
        for c in range(n):
            rc = r*n+c
            for gr in  mcf.graph[rc]:
                if gr.to == ci[c] and gr.cap == 0:
                    ra[r][c] = 'X'

    return f"{res}\n" + JAA(ra, "\n", "")


print(main())


