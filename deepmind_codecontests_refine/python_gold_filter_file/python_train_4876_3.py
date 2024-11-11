mod=10**9+7

class Dijkstra():
    """ ダイクストラ法
    重み付きグラフにおける単一始点最短路アルゴリズム

    * 使用条件
        - 負のコストがないこと
        - 有向グラフ、無向グラフともにOK

    * 計算量はO(E*log(V))

    * ベルマンフォード法より高速なので、負のコストがないならばこちらを使うとよい
    """
    class Edge():
        """ 重み付き有向辺 """
        def __init__(self, _to, _cost):
            self.to = _to
            self.cost = _cost

    def __init__(self, V):
        """ 重み付き有向辺
        無向辺を表現したいときは、_fromと_toを逆にした有向辺を加えればよい

        Args:
            V(int): 頂点の数
        """
        self.G = [[] for i in range(V)]  # 隣接リストG[u][i] := 頂点uのi個目の隣接辺
        self._E = 0  # 辺の数
        self._V = V  # 頂点の数

    @property
    def E(self):
        """ 辺数
        無向グラフのときは、辺数は有向グラフの倍になる
        """
        return self._E

    @property
    def V(self):
        """ 頂点数 """
        return self._V

    def add(self, _from, _to, _cost):
        """ 2頂点と、辺のコストを追加する """
        self.G[_from].append(self.Edge(_to, _cost))
        self._E += 1

    def edge(self,_from):
        return self.G[_from]

    def shortest_path(self, s):
        """ 始点sから頂点iまでの最短路を格納したリストを返す
        Args:
            s(int): 始点s
        Returns:
            d(list): d[i] := 始点sから頂点iまでの最短コストを格納したリスト。
                     到達不可の場合、値はfloat("inf")
        """
        import heapq
        que = []  # プライオリティキュー（ヒープ木）
        d = [10**15] * self.V
        d[s] = 0
        cnt=[0]*self.V
        cnt[s]=1
        heapq.heappush(que, (0, s))  # 始点の(最短距離, 頂点番号)をヒープに追加する

        while len(que) != 0:
            cost, v = heapq.heappop(que)
            # キューに格納されている最短経路の候補がdの距離よりも大きければ、他の経路で最短経路が存在するので、処理をスキップ
            if d[v] < cost: continue

            for i in range(len(self.G[v])):
                # 頂点vに隣接する各頂点に関して、頂点vを経由した場合の距離を計算し、今までの距離(d)よりも小さければ更新する
                e = self.G[v][i]  # vのi個目の隣接辺e
                if d[e.to] > d[v] + e.cost:
                    d[e.to] = d[v] + e.cost  # dの更新
                    heapq.heappush(que, (d[e.to], e.to))  # キューに新たな最短経路の候補(最短距離, 頂点番号)の情報をpush
                    cnt[e.to]=cnt[v]%mod
                elif d[e.to]==d[v]+e.cost:
                    cnt[e.to]+=cnt[v]
                    cnt[e.to]%=mod
        return d,cnt

import sys

input=sys.stdin.readline
sys.setrecursionlimit(1000000)

N,M=map(int,input().split())
S,T=map(int,input().split())
mati=Dijkstra(N)
for i in range(M):
    u,v,d=map(int,input().split())
    mati.add(u-1,v-1,d)
    mati.add(v-1,u-1,d)

spath,Sways=mati.shortest_path(S-1)
tpath,Tways=mati.shortest_path(T-1)

ans=Sways[T-1]*Tways[S-1]
ans%=mod
for u in range(N):
    for e in mati.edge(u):
        v=e.to
        d=e.cost
        ans-=(Tways[v]*Sways[u])**2*(spath[u]+d+tpath[v]==spath[T-1] and spath[u]+d!=tpath[v] and spath[u]!=tpath[v]+d and (tpath[v]+d>=spath[u]>=tpath[v] or tpath[v]+d>=spath[u]+d>=tpath[v]))
        ans%=mod

for i in range(N):
    ans-=(Tways[i]*Sways[i])**2*(spath[i]+tpath[i]==spath[T-1] and spath[i]==tpath[i])
    ans%=mod

print(ans%mod)
