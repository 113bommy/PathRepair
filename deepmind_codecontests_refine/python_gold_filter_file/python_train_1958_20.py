import sys
from itertools import combinations, permutations, product, combinations_with_replacement, accumulate
from heapq import heapify, heappop, heappush, heappushpop
from bisect import bisect_left, bisect_right
from collections import Counter, defaultdict, deque
from math import sqrt, log, floor, ceil, factorial, cos, sin, pi  # , gcd
from fractions import gcd
from operator import mul
from functools import reduce

sys.setrecursionlimit(10 ** 8)
input = sys.stdin.readline
INF = float('inf')
LINF = 2 ** 63 - 1
NIL = -LINF
MOD = 10 ** 9 + 7
MGN = 4


def AST(exp: bool, msg: str = ""): assert exp, msg


def TAST(exp: bool, msg=""):
    if exp is False: print("TAssertionError:", msg)
    while exp is False:
        pass


def EPR(msg): print(msg, file=sys.stderr)


def II(): return int(input())


def IF(): return float(input())


def IS(): return input().replace('\n', '')


def ILCI(n: int): return [II() for _ in range(n)]


def ILCF(n: int): return [IF() for _ in range(n)]


def ILI(): return list(map(int, input().split()))


def ILLI(n: int): return [[int(j) for j in input().split()] for i in range(n)]


def ILF(): return list(map(float, input().split()))


def ILLF(n: int): return [[float(j) for j in input().split()] for i in range(n)]


def LTOS(lst: list, sep: str = ' '): return sep.join(map(str, lst))


def DEC(lst: list): return list(map(lambda x: x - 1, lst))


def INC(lst: list): return list(map(lambda x: x + 1, lst))


class Queue:
    def __init__(self) -> None:
        self.items = deque()

    def is_empty(self) -> bool:
        return len(self.items) == 0

    def enqueue(self, item) -> None:
        self.items.appendleft(item)

    def insert(self, item) -> None:
        self.enqueue(item)

    def dequeue(self):
        return self.items.pop()

    def front(self):
        return self.items[-1]

    def pop(self) -> None:
        self.items.pop()

    def size(self) -> int:
        return len(self.items)


class LCA:
    def __init__(self, N: int) -> None:
        self.N = N
        self.to = [[] for _ in range(N)]
        self.co = [[] for _ in range(N)]
        self.dep = [0] * N
        self.costs = [0] * N
        l = 0
        while (1 << l) < N:
            l += 1
        self.l = l
        self.par = [([0] * l) for _ in range(N + 1)]

    def add_edge(self, a: int, b: int, c=0) -> None:
        self.to[a].append(b)
        self.co[a].append(c)
        self.to[b].append(a)
        self.co[b].append(c)

    '''
    def _dfs(self, v: int, d: int = 0, c = 0, p: int = -1) -> None:
        if p != -1:
            self.par[v][0] = p
        self.dep[v] = d
        self.costs[v] = c
        for i in range(len(self.to[v])):
            u = self.to[v][i]
            if u == p:
                continue
            else:
                self._dfs(u, d+1, c+self.co[v][i], v)
    '''

    def _bfs(self, root: int) -> None:
        que = Queue()
        que.enqueue(root)
        self.dep[root] = 0
        self.costs[root] = 0
        vis = [False] * self.N
        while que.is_empty() is False:
            v = que.dequeue()
            vis[v] = True
            nd = self.dep[v] + 1
            cs = self.costs[v]
            for i in range(len(self.to[v])):
                nv = self.to[v][i]
                if vis[nv]:
                    continue
                else:
                    que.enqueue(nv)
                    self.dep[nv] = nd
                    self.costs[nv] = cs + self.co[v][i]
                    self.par[nv][0] = v

    def init(self, root: int = 0) -> None:
        self.root = root
        self._bfs(root)
        for i in range(self.l - 1):
            for v in range(self.N):
                self.par[v][i + 1] = self.par[self.par[v][i]][i]

    def lca(self, a: int, b: int) -> int:
        dep_s, dep_l = self.dep[a], self.dep[b]
        if dep_s > dep_l:
            a, b = b, a
            dep_s, dep_l = dep_l, dep_s
        gap = dep_l - dep_s
        L_1 = self.l - 1
        par = self.par
        for i in range(L_1, -1, -1):
            leng = 1 << i
            if gap >= leng:
                gap -= leng
                b = par[b][i]
        if a == b:
            return a
        for i in range(L_1, -1, -1):
            na = par[a][i]
            nb = par[b][i]
            if na != nb:
                a, b = na, nb
        return par[a][0]

    def length(self, a: int, b: int) -> int:
        c = self.lca(a, b)
        dep = self.dep
        return dep[a] + dep[b] - dep[c] * 2

    def dist(self, a: int, b: int):
        c = self.lca(a, b)
        costs = self.costs
        return costs[a] + costs[b] - costs[c] * 2


def main():
    N, Q = ILI()
    gr = LCA(N)
    es = [[] for _ in range(N)]
    for i in range(N - 1):
        a, b, col, dist = ILI()
        a -= 1;
        b -= 1
        es[a].append((b, dist, col))
        es[b].append((a, dist, col))
        gr.add_edge(a, b, dist)

    gr.init()
    ans = [0] * Q
    qs = [[] for _ in range(N)]
    for i in range(Q):
        cx, dy, a, b = ILI()
        a -= 1;
        b -= 1
        # ans[i] = gr.dist(a, b)
        c = gr.lca(a, b)
        ans[i] = gr.costs[a] + gr.costs[b] - gr.costs[c] * 2
        qs[a].append((cx, i, 1, dy))
        qs[b].append((cx, i, 1, dy))
        qs[c].append((cx, i, -2, dy))

    cnt = [0] * N
    sum_ = [0] * N

    '''
    def dfs(v: int, p: int = -1) -> None:
        for (col, qid, coeff, dist) in qs[v]:
            x = -sum_[col]
            x += dist * cnt[col]
            ans[qid] += x * coeff

        for (to, co, col) in es[v]:
            if to == p:
                continue
            cnt[col] += 1
            sum_[col] += co

            dfs(to, v)

            cnt[col] -= 1
            sum_[col] -= co
    '''

    sk = []
    tr = [{} for _ in range(N+1)]
    vis = [False] * (N+1)

    def dfs2(v: int, p: int = -1) -> None:
        for (col, qid, coeff, dist) in qs[v]:
            x = -sum_[col]
            x += dist * cnt[col]
            ans[qid] += x * coeff

        vis[v] = True

        for (to, co, col) in reversed(es[v]):
            if to == p:
                continue
            sk.append((to, v, col, co))
            tr[v][to] = (col, co)

        while len(sk) > 0:
            v, p, cl, cs = sk[-1]
            if len(es[v]) == 1:
                sk.pop()

            if vis[v] and p >= 0:
                cl, cs = tr[p][v]
                cnt[cl] -= 1
                sum_[cl] -= cs
                tr[p].pop(v)
                sk.pop()
                continue

            cnt[cl] += 1
            sum_[cl] += cs

            for (col, qid, coeff, dist) in qs[v]:
                x = -sum_[col]
                x += dist * cnt[col]
                ans[qid] += x * coeff

            vis[v] = True

            for (to, co, col) in reversed(es[v]):
                if to == p:
                    continue
                sk.append((to, v, col, co))
                tr[v][to] = (col, co)

            if len(tr[v]) == 0 and p >= 0:
                cl, cs = tr[p][v]
                cnt[cl] -= 1
                sum_[cl] -= cs
                tr[p].pop(v)

    dfs2(0)

    print(*ans, sep='\n')


if __name__ == '__main__':
    main()
