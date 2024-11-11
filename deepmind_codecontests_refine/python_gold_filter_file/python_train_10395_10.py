import sys

sys.setrecursionlimit(10**7)
def MI(): return map(int,sys.stdin.readline().rstrip().split())
def LS2(): return list(sys.stdin.readline().rstrip())


from collections import deque


class Dinic:
    def __init__(self, N, inf):
        self.N = N
        self.inf = inf
        self.G = [[] for _ in range(N)]
        self.level = [0]*N

    def add_edge(self, fr, to, cap):
        forward = [to, cap, None]
        forward[2] = backward = [fr, 0, forward]
        self.G[fr].append(forward)
        self.G[to].append(backward)

    def add_multi_edge(self, v1, v2, cap1, cap2):
        edge1 = [v2, cap1, None]
        edge1[2] = edge2 = [v1, cap2, edge1]
        self.G[v1].append(edge1)
        self.G[v2].append(edge2)

    def bfs(self, s):
        self.level = [-1]*self.N
        deq = deque([s])
        self.level[s] = 0
        while deq:
            v = deq.pop()
            lv = self.level[v] + 1
            for w, cap, _ in self.G[v]:
                if cap > 0 and self.level[w] == -1:
                    self.level[w] = lv
                    deq.appendleft(w)

    def dfs(self, v, t, f):
        if v == t:
            return f
        for e in self.iter[v]:
            w, cap, rev = e
            if cap > 0 and self.level[v] < self.level[w]:
                d = self.dfs(w, t, min(f, cap))
                if d > 0:
                    e[1] -= d
                    rev[1] += d
                    return d
        return 0

    def flow(self, s, t):
        flow = 0
        while True:
            self.bfs(s)
            if self.level[t] == -1:
                return flow
            *self.iter, = map(iter, self.G)
            f = self.inf
            while f > 0:
                f = self.dfs(s, t, self.inf)
                flow += f


H,W = MI()
inf = 10**5
Di = Dinic(H+W+2,inf)
s,t = H+W,H+W+1
for i in range(H):
    S = LS2()
    for j in range(W):
        if S[j] == 'S':
            Di.add_edge(s,i,inf)
            Di.add_edge(s,j+H,inf)
        elif S[j] == 'T':
            Di.add_edge(i,t,inf)
            Di.add_edge(j+H,t,inf)
        elif S[j] == 'o':
            Di.add_edge(i,j+H,1)
            Di.add_edge(j+H,i,1)

ans = Di.flow(s,t)
print(ans if ans < inf else -1)
