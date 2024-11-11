from collections import deque


class Dinic:
    def __init__(self, n: int):
        self.INF = 10**9 + 7
        self.n = n
        self.graph = [[] for _ in range(n)]
 
    def add_edge(self, _from: int, to: int, capacity: int):
        """残余グラフを構築
        1. _fromからtoへ向かう容量capacityの辺をグラフに追加する
        2. toから_fromへ向かう容量0の辺をグラフに追加する
        """
        forward = [to, capacity, None]
        forward[2] = backward = [_from, 0, forward]
        self.graph[_from].append(forward)
        self.graph[to].append(backward)
 
    def bfs(self, s: int, t: int):
        """capacityが正の辺のみを通ってsからtに移動可能かどうかBFSで探索
        level: sからの最短路の長さ
        """
        self.level = [-1] * self.n
        q = deque([s])
        self.level[s] = 0
        while q:
            _from = q.popleft()
            for to, capacity, _ in self.graph[_from]:
                if capacity > 0 and self.level[to] < 0:
                    self.level[to] = self.level[_from] + 1
                    q.append(to)
 
    def dfs(self, _from: int, t: int, f: int) -> int:
        """流量が増加するパスをDFSで探索
        BFSによって作られた最短路に従ってfを更新する
        """
        if _from == t:
            return f
        for edge in self.itr[_from]:
            to, capacity, reverse_edge = edge
            if capacity > 0 and self.level[_from] < self.level[to]:
                d = self.dfs(to, t, min(f, capacity))
                if d > 0:
                    edge[1] -= d
                    reverse_edge[1] += d
                    return d
        return 0
 
    def max_flow(self, s: int, t: int):
        """s-tパス上の最大流を求める
        計算量: O(|E||V|^2)
        """
        flow = 0
        while True:
            self.bfs(s, t)
            if self.level[t] < 0:
                break
            self.itr = list(map(iter, self.graph))
            f = self.dfs(s, t, self.INF)
            while f > 0:
                flow += f
                f = self.dfs(s, t, self.INF)
        return flow


h, w = map(int, input().split())
a = [list(input()) for i in range(h)]

di = Dinic(h + w + 2)
for i in range(h):
    for j in range(w):
        if a[i][j] == "o":
            di.add_edge(i, h + j, 1)
            di.add_edge(h + j, i, 1)
        if a[i][j] == "S":
            di.add_edge(h + w, i, 10 ** 5)
            di.add_edge(h + w, h + j, 10 ** 5)
        if a[i][j] == "T":
            di.add_edge(i, h + w + 1, 10 ** 5)
            di.add_edge(h + j, h + w + 1, 10 ** 5)

ans = di.max_flow(h + w, h + w + 1)
if ans >= 10 ** 5:
    print(-1)
else:
    print(ans)