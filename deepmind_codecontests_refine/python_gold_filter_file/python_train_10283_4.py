N,K = map(int,input().split())
A = [list(map(int,input().split())) for i in range(N)]

import heapq
class MinCostFlow:
    def __init__(self, n):
        self.n = n
        self.es = [[] for _ in range(n)] #[[to,rev,cap,cost], ...]
        self.pos = []

    def add_edge(self, fr, to, cap, cost):
        m = len(self.pos)
        self.pos.append((fr, len(self.es[fr])))
        self.es[fr].append([to, len(self.es[to]), cap, cost])
        self.es[to].append([fr, len(self.es[fr])-1, 0, -cost])
        return m

    def get_edges(self):
        ret = []
        for fr,i in self.pos:
            to,rev,cap,cost = self.es[fr][i]
            flow = self.es[to][rev][2]
            cap += flow
            ret.append((fr, to, cap, flow, cost))
        return ret

    def flow(self, s, t, flow_limit=2**63):
        return self.slope(s,t,flow_limit)[-1]

    def slope(self, s, t, flow_limit=2**63):
        self.dual = [0] * self.n
        self.dist = [2**63] * self.n
        self.pv = [-1] * self.n
        self.pe = [-1] * self.n
        self.vis = [False] * self.n
        def _dual_ref():
            self.dist = [2**63] * self.n
            self.pv = [-1] * self.n
            self.pe = [-1] * self.n
            self.vis = [False] * self.n
            hq = [(0,s)]
            self.dist[s] = 0
            while hq:
                p = heapq.heappop(hq)
                v = p[1]
                if self.vis[v]: continue
                self.vis[v] = True
                if v==t: break
                for i,(to,rev,cap,cost) in enumerate(self.es[v]):
                    if self.vis[to] or not cap: continue
                    _cost = cost - self.dual[to] + self.dual[v]
                    if self.dist[to] - self.dist[v] > _cost:
                        self.dist[to] = self.dist[v] + _cost
                        self.pv[to] = v
                        self.pe[to] = i
                        heapq.heappush(hq, (self.dist[to],to))
            if not self.vis[t]:
                return False
            for v in range(self.n):
                if not self.vis[v]: continue
                self.dual[v] -= self.dist[t] - self.dist[v]
            return True
        flow, cost, prev_cost = 0, 0, -1
        ret = [(flow, cost)]
        while flow < flow_limit:
            if not _dual_ref(): break
            c = flow_limit - flow
            v = t
            while v != s:
                c = min(c, self.es[self.pv[v]][self.pe[v]][2])
                v = self.pv[v]
            v = t
            while v != s:
                self.es[self.pv[v]][self.pe[v]][2] -= c
                self.es[v][self.es[self.pv[v]][self.pe[v]][1]][2] += c
                v = self.pv[v]
            d = -self.dual[s]
            flow += c
            cost += c * d
            if prev_cost == d:
                ret.pop()
            ret.append((flow, cost))
            prev_cost = cost
        return ret

mcf = MinCostFlow(2*N + 2)
src,dst = 2*N, 2*N+1

BIG = 10**9
mcf.add_edge(src, dst, N*K, BIG)
for i in range(N):
    mcf.add_edge(src, i, K, 0)
    mcf.add_edge(N+i, dst, K, 0)
for i,row in enumerate(A):
    for j,a in enumerate(row):
        mcf.add_edge(i, N+j, 1, BIG - a)

_,mincost = mcf.flow(src, dst, N*K)
ans = [['.']*N for _ in range(N)]
print(N*K*BIG - mincost)
for fr,to,cap,flow,cost in mcf.get_edges():
    if fr == src or to == dst or flow == 0: continue
    ans[fr][to - N] = 'X'
for row in ans:
    print(''.join(row))