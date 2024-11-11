import math
import sys
from collections import defaultdict
sys.setrecursionlimit(200000)

def dfs(here, p, d, parent, depth, connect):
    parent[0][here] = p
    depth[here] = d
    for next_v in connect[here]:
        dfs(next_v, here, d + 1, parent, depth, connect)

def lca(v1, v2, parent, depth):
    if depth[v2] > depth[v1]:
        v1, v2 = v2, v1
    for i in range(max_log):
        if depth[v1] - depth[v2] >> i & 1:
            v1 = parent[i][v1]
    if v1 == v2:
        return v2
    for i in range(max_log - 1, -1, -1):
        if parent[i][v1] != parent[i][v2]:
            v1 = parent[i][v1]
            v2 = parent[i][v2]
    return parent[0][v1]

connect = defaultdict(list)
v_num = int(input())
root = 0
for i in range(v_num):
    edge = [int(n) for n in input().split(" ")]
    connect[i].extend(edge[1:])
depth = [-1 for n in range(v_num)]
max_log = max(int(math.log(v_num, 2)), 1)
parent = [[-1 for n in range(v_num)] for m in range(max_log)]
dfs(root, -1, 0, parent, depth, connect)
for i in range(max_log - 1):
    for v in range(v_num):
        parent[i + 1][v] = -1 if parent[i][v] < 0 else parent[i][parent[i][v]]
q_num = int(input())
for _ in range(q_num):
    v1, v2 = (int(n) for n in input().split(" ") )
    print(lca(v1, v2, parent, depth))