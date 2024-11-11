#!/usr/bin/env python3

from collections import defaultdict
# クラスカル法を使う

V, E = map(int, input().split())
D = 0
tree = []
vertices = defaultdict(set)
for i in range(V):
    tree.append(i)          # 全ての頂点は自分の頂点 index と同じ index の木に属す
    vertices[i].add(i)

edges = []
for i in range(E):
    s, t, d = map(int, input().split())
    edges.append((s, t, d))

edges.sort(key=lambda x: x[2])
while edges:
    if V == 1:
        break
    s, t, d = edges.pop(0)
    if tree[s] != tree[t]:
        new = min(tree[s], tree[t])
        old = max(tree[s], tree[t])
        vertices[new] = vertices[new] | vertices[old]
        for vertex in vertices[old]:
            tree[vertex] = new

        D += d
        V -= 1
print(D)