# -*- coding: utf-8 -*-

import sys

def input(): return sys.stdin.readline().strip()
def list2d(a, b, c): return [[c] * b for i in range(a)]
def list3d(a, b, c, d): return [[[d] * c for j in range(b)] for i in range(a)]
def list4d(a, b, c, d, e): return [[[[e] * d for j in range(c)] for j in range(b)] for i in range(a)]
def ceil(x, y=1): return int(-(-x // y))
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(N=None): return list(MAP()) if N is None else [INT() for i in range(N)]
def Yes(): print('Yes')
def No(): print('No')
def YES(): print('YES')
def NO(): print('NO')
sys.setrecursionlimit(10 ** 9)
INF = 10 ** 18
MOD = 10 ** 9 + 7

def popcount(i):
    return bin(i).count('1')

def dfs(i, N, nodes, src, dest):
    """ DFS(木、再帰、重みなし) """

    dist = [INF] * N
    def rec(u, prev, c):
        if u == dest:
            return True
        dist[u] = c
        for v in nodes[u]:
            if v != prev:
                if rec(v, u, c+1):
                    # 目的の頂点に到達したら、それに至る辺集合をbitで持っておく
                    A[i] |= 1 << edges[(u, v)]
                    return True
        return False
    rec(src, -1, 0)

N = INT()
nodes = [[] for i in range(N)]
edges = {}
for i in range(N-1):
    a, b = MAP()
    a -= 1; b -= 1
    nodes[a].append(b)
    nodes[b].append(a)
    edges[(a, b)] = i
    edges[(b, a)] = i

M = INT()
# A[i] := 条件iで白くしなければいけない辺の集合
A = [0] * M
for i in range(M):
    u, v = MAP()
    u -= 1; v -= 1
    dfs(i, N, nodes, u, v)

# 全通り数から、包除原理に基づいて足し引きしていく
ans = 2 ** (N-1)
for S in range(1, 1<<M):
    # Sで表される条件の集合において、白くしなければならない辺の集合S2
    S2 = 0
    for i in range(M):
        if S & 1<<i:
            S2 |= A[i]
    # 白くしなければならない辺の数
    edgecnt = popcount(S2)
    # 今回の状態Sを作るパターンの通り数(2^白黒自由に選べる辺の数)
    cnt = 2**(N-1-edgecnt)
    if popcount(S) % 2 == 1:
        ans -= cnt
    else:
        ans += cnt
print(ans)
