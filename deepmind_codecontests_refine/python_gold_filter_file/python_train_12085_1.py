import sys
from operator import itemgetter

sys.setrecursionlimit(200000)


def dfs(u, prev):
    global post_order, pre_order

    pre_order.append((u, prev))
    for w, t in edges[u]:
        if t != prev:
            dfs(t, u)
    post_order.append(u)


n = int(input())
edges = [set() for _ in range(n)]

for _ in range(n - 1):
    s, t, w = map(int, input().split())
    edges[s].add((w, t))
    edges[t].add((w, s))

post_order, pre_order = [], []
farthest = [{} for _ in range(n)]
height = [0] * n

if n > 1:
    dfs(0, None)

for i in post_order:
    for w, t in edges[i]:
        farthest[i][t] = w + max((d for tt, d in farthest[t].items() if tt != i), default=0)
for i, parent in pre_order:
    sorted_farthest = sorted(farthest[i].items(), key=itemgetter(1))
    max_t, max_d = sorted_farthest.pop()
    height[i] = max_d
    for w, t in edges[i]:
        if t == parent:
            continue
        farthest[t][i] = w + ((max_d if t != max_t else sorted_farthest[-1][1]) if sorted_farthest else 0)
for h in height:
    print(h)