import bisect
import math
import os
import sys
from collections import defaultdict

if os.getenv("LOCAL"):
    sys.stdin = open("_in.txt", "r")

sys.setrecursionlimit(2147483647)
INF = float("inf")
IINF = 10 ** 18
MOD = 10 ** 9 + 7



class SparseTable:
    """
    構築 O(NlogN)、クエリ O(1)
    """

    def __init__(self, values, fn):
        """
        :param list values:
        :param callable fn: 結合則を満たす冪等な関数。min、max など。add はだめ
        """
        self._values = values
        self._fn = fn

        # SparseTable を構築
        # self._table[i][p]: [i, i+2^p) に fn を適用した結果の値のインデックス
        self._table = self._build(values, fn)

        # self._msb[i]: 最上位ビット; どの p を見るべきか
        self._msb = [0] * (len(values) + 1)
        for i in range(2, len(values) + 1):
            self._msb[i] = self._msb[i >> 1] + 1

    @staticmethod
    def _build(values, fn):
        # AtCoder の PyPy 2.4.0 では math.log2 が使えない
        size = int(math.log(len(values), 2)) + 1

        st = [[0] * size for _ in range(len(values))]
        for i in range(len(values)):
            st[i][0] = i
        for p in range(1, size):
            for i in range(len(values)):
                q = min(i + (1 << (p - 1)), len(values) - 1)
                l = st[i][p - 1]
                r = st[q][p - 1]
                if values[l] == fn(values[l], values[r]):
                    st[i][p] = l
                else:
                    st[i][p] = r
        return st

    def get(self, a, b):
        """
        半開区間 [a, b) に fn を適用した結果
        :param int a:
        :param int b:
        """
        if b <= a:
            return None
        p = self._msb[b - a]
        return self._fn(
            self._values[self._table[a][p]],
            self._values[self._table[b - (1 << p)][p]]
        )


def eulerian_trail(tree, max_v, root=0):
    """
    木のオイラー路; オイラーツアー
    :param list of (list of (int, int, int)) tree:
    :param int max_v:
    :param int root:
    :return: (trails, depths)
    :rtype: (list of int, list of int, list of (int, int))
    """
    seen = [False] * (max_v + 1)
    # 頂点の履歴
    trails = []
    # 深さの履歴
    depths = []
    # list of (color, weight)
    edges = []
    # Overflow 回避のためループで
    stack = [(root, 0, (0, 0), True)]
    while stack:
        v, d, edge, forward = stack.pop()
        seen[v] = True
        trails.append(v)
        depths.append(d)
        edges.append(edge)
        if not forward:
            continue
        for u, c, w in tree[v]:
            if not seen[u]:
                stack.append((v, d, (c, -w), False))
                stack.append((u, d + 1, (c, w), True))
    return trails, depths, edges


N, Q = list(map(int, sys.stdin.readline().split()))
ABCD = [list(map(int, sys.stdin.readline().split())) for _ in range(N - 1)]
XYVU = [list(map(int, sys.stdin.readline().split())) for _ in range(Q)]

#: :type: list of (list of (int, int, int))
graph = [[] for _ in range(N + 1)]
for a, b, c, d in ABCD:
    graph[a].append((b, c, d))
    graph[b].append((a, c, d))

trails, depths, edges = eulerian_trail(graph, max_v=N, root=1)
ids = [-1] * (N + 1)
for i, t in enumerate(trails):
    ids[t] = i

distances = []
color_dist = defaultdict(lambda: [(-1, 0)])
color_cnt = defaultdict(lambda: [(-1, 0)])
s = 0
for i, (c, d) in enumerate(edges):
    s += d
    distances.append(s)

    color_dist[c].append((i, color_dist[c][-1][1] + d))
    _, cc = color_cnt[c][-1]
    color_cnt[c].append((i, cc + 1 if d > 0 else cc - 1))

st = SparseTable(values=list(zip(depths, trails)), fn=min)


def get_lca(v, u):
    iv, iu = ids[v], ids[u]
    if iv > iu:
        iv, iu = iu, iv
    _, ret = st.get(iv, iu + 1)
    return ret


def distance(v):
    # v から root までの距離
    return distances[ids[v]]


def count_color(v, c):
    # v から root までの c の数
    iv = ids[v]
    i = bisect.bisect_left(color_cnt[c], (iv + 1, 0))
    return color_cnt[c][i - 1][1]


def distance_color(v, c):
    # v から root までの c の数
    iv = ids[v]
    i = bisect.bisect_left(color_dist[c], (iv + 1, 0))
    return color_dist[c][i - 1][1]


for x, y, u, v in XYVU:
    lca = get_lca(u, v)
    d = distance(u) + distance(v) - distance(lca) * 2
    c = count_color(u, x) + count_color(v, x) - count_color(lca, x) * 2
    s = distance_color(u, x) + distance_color(v, x) - distance_color(lca, x) * 2
    print(d - s + c * y)
