#!/usr/bin/env python3

import sys

sys.setrecursionlimit(1000000)

n, m = [int(x) for x in input().split()]
edges = []
g = [[] for _ in range(n)]
for _ in range(m):
    a, b = [int(x) for x in input().split()]
    a -= 1
    b -= 1
    e = len(edges)
    g[a].append(e)
    g[b].append(e)
    edges.append((a, b))

if m % 2 == 1:
    print(-1)
    sys.exit(0)


visited = [False] * n
visitede = [False] * m


def build_stree(i):
    cts = []
    for e in g[i]:
        j = edges[e][1 if edges[e][0] == i else 0]
        if visited[j]:
            continue
        visitede[e] = True
        visited[j] = True
        cts.append((e, build_stree(j)))
    return i, cts


visited[0] = True
st = build_stree(0)

rev_e = [None if v else False for v in visitede]


def pos(t):
    i, cts = t
    for _, ct in cts:
        pos(ct)
    es = [e for e in g[i] if rev_e[e] is None]
    assert len(es) <= 1
    if not es:
        return
    f = es[0]
    rev_e[f] = (sum(
        (edges[e][0] == i) ^ rev_e[e]
        for e in g[i] if e != f
    ) % 2 != 0) ^ (edges[f][0] == i)


pos(st)

for ed, re in zip(edges, rev_e):
    if re:
        b, a = ed
    else:
        a, b = ed
    print(a + 1, b + 1)
