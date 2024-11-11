import heapq

class mcf_graph:


    def __init__(self, n):
        self.n = n
        self.pos = []
        self.g = [[] for _ in range(n)]


    def add_edge(self, from_, to, cap, cost):
        assert 0 <= from_ < self.n
        assert 0 <= to < self.n
        m = len(self.pos)
        self.pos.append((from_, len(self.g[from_])))
        self.g[from_].append(self.__class__._edge(to, len(self.g[to]), cap, cost))
        self.g[to].append(self.__class__._edge(from_, len(self.g[from_]) - 1, 0, -cost))
        return m


    class edge:
        def __init__(self, from_, to, cap, flow, cost):
            self.from_ = from_
            self.to = to
            self.cap = cap
            self.flow = flow
            self.cost = cost


    def get_edge(self, i):
        _e = self.g[self.pos[i][0]][self.pos[i][1]]
        _re = self.g[_e.to][_e.rev]
        return self.__class__.edge(self.pos[i][0], _e.to, _e.cap + _re.cap, _re.cap, _e.cost)


    def edges(self):
        ret = []
        for i in range(len(self.pos)):
            _e = self.g[self.pos[i][0]][self.pos[i][1]]
            _re = self.g[_e.to][_e.rev]
            ret.append(self.__class__.edge(self.pos[i][0], _e.to, _e.cap + _re.cap, _re.cap, _e.cost))
        return ret


    def slope(self, s, t, flow_limit=float('inf')):
        assert 0 <= s < self.n
        assert 0 <= t < self.n
        assert s != t
        
        dual = [0] * self.n
        dist = [float('inf')] * self.n
        pv = [-1] * self.n
        pe = [-1] * self.n
        vis = [False] * self.n

        def _dual_ref():
            nonlocal dual, dist, pv, pe, vis
            dist = [float('inf')] * self.n
            pv = [-1] * self.n
            pe = [-1] * self.n
            vis = [False] * self.n

            que = [(0, s)]
            dist[s] = 0
            while que:
                _, v = heapq.heappop(que)
                if vis[v]:
                    continue
                vis[v] = True
                if v == t:
                    break
                for i in range(len(self.g[v])):
                    e = self.g[v][i]
                    if vis[e.to] or e.cap == 0:
                        continue
                    cost = e.cost - dual[e.to] + dual[v]
                    if dist[e.to] > dist[v] + cost:
                        dist[e.to] = dist[v] + cost
                        pv[e.to] = v
                        pe[e.to] = i
                        heapq.heappush(que, (dist[e.to], e.to))
            if not vis[t]:
                return False

            for v in range(self.n):
                if not vis[v]:
                    continue
                dual[v] -= dist[t] - dist[v]
            
            return True

        flow = 0
        cost = 0
        prev_cost = -1
        result = [(flow, cost)]
        while flow < flow_limit:
            if not _dual_ref():
                break
            c = flow_limit - flow
            v = t
            while v != s:
                c = min(c, self.g[pv[v]][pe[v]].cap)
                v = pv[v]
            v = t
            while v != s:
                e = self.g[pv[v]][pe[v]]
                e.cap -= c
                self.g[v][e.rev].cap += c
                v = pv[v]
            d = -dual[s]
            flow += c
            cost += c * d
            if prev_cost == d:
                result.pop()
            result.append((flow, cost))
            prev_cost = cost
        return result


    def flow(self, s, t, flow_limit=float('inf')):
        return self.slope(s, t, flow_limit)[-1]

    
    class _edge:
        def __init__(self, to, rev, cap, cost):
            self.to = to
            self.rev = rev
            self.cap = cap
            self.cost = cost


BIG = 10 ** 9

import sys
input = sys.stdin.readline

N, K = map(int, input().split())

g = mcf_graph(2 * N + 2)
s = 2 * N
t = 2 * N + 1

g.add_edge(s, t, N * K, BIG)
for i in range(N):
    g.add_edge(s, i, K, 0)
    g.add_edge(N + i, t, K, 0)

for i in range(N):
    As = map(int, input().split())
    for j, A in enumerate(As):
        g.add_edge(i, N + j, 1, BIG - A)

result = g.flow(s, t, N * K)

print(N * K * BIG - result[1])

grid = [['.' for _ in range(N)] for _ in range(N)]
edges = g.edges()
for e in edges:
    if e.from_ == s or e.to == t or e.flow == 0:
        continue
    grid[e.from_][e.to - N] = 'X'

for row in grid:
    print(''.join(row))