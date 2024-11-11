import sys

sys.setrecursionlimit(1000000)

class Node():
    def __init__(self, p, l, r):
        self.p = p
        self.l = l
        self.r = r


def rec(u, p):
    D[u] = p
    if T[u].r != -1:
        rec(T[u].r, p)
    if T[u].l != -1:
        rec(T[u].l, p + 1)


N = int(input())
T = [Node(-1, -1, -1) for _ in range(N)]
D = [-1] * N
for i in range(N):
    i, k, *cs = map(int, input().split())
    for j, c in enumerate(cs):
        if j == 0:
            T[i].l = c
        else:
            T[l].r = c
        l = c
        T[c].p = i
for i, t in enumerate(T):
    if t.p == -1:
        r = i
rec(r, 0)
for i, t in enumerate(T):
    cs = []
    c = t.l
    while c != -1:
        cs.append(c)
        c = T[c].r
    if t.p == -1:
        print('node {}: parent = {}, depth = {}, root, {}'
              .format(i, t.p, D[i], cs))
    elif t.l == -1:
        print('node {}: parent = {}, depth = {}, leaf, {}'
              .format(i, t.p, D[i], cs))
    else:
        print('node {}: parent = {}, depth = {}, internal node, {}'
              .format(i, t.p, D[i], cs))

