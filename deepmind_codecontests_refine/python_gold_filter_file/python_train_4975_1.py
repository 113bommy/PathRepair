import os
import sys

if os.getenv("LOCAL"):
    sys.stdin = open("_in.txt", "r")

sys.setrecursionlimit(10 ** 9)
INF = float("inf")
IINF = 10 ** 18
MOD = 10 ** 9 + 7


# MOD = 998244353


def eulerian_trail(tree, max_v, root=0):
    """
    木のオイラー路; オイラーツアー
    :param list of (list of (int, int)) tree:
    :param int max_v:
    :param int root:
    :return: (trails, depths, weights)
    :rtype: (list of int, list of int, list of int)
    """
    seen = [False] * (max_v + 1)
    # 頂点の履歴
    trails = []
    # 深さの履歴
    depths = []
    # 距離の履歴
    weights = []
    # Overflow 回避のためループで
    stack = [(root, 0, 0, True)]
    while stack:
        v, d, w, forward = stack.pop()
        seen[v] = True
        trails.append(v)
        depths.append(d)
        weights.append(w)
        if not forward:
            continue

        for u, w in tree[v]:
            if not seen[u]:
                stack.append((v, d, -w, False))
                stack.append((u, d + 1, w, True))
    return trails, depths, weights


N = int(sys.stdin.buffer.readline())
AB = [list(map(int, sys.stdin.buffer.readline().split())) for _ in range(N - 1)]
graph = [[] for _ in range(N)]

# AB = generate_tree(N)
# plot_graph(AB)
# for a, b in AB:
#     graph[a].append((b, 1))
#     graph[b].append((a, 1))

for a, b in AB:
    a -= 1
    b -= 1
    graph[a].append((b, 1))
    graph[b].append((a, 1))

counts = [N // 3, (N + 2) // 3, (N + 1) // 3]

# 二部グラフ
vs, _, _ = eulerian_trail(graph, N - 1)
bp = [0] * N
for i, v in enumerate(vs):
    bp[v] = i & 1


ansmod = [-1] * N
if bp.count(0) <= counts[0]:
    # 3を割り当てる
    for v, b in enumerate(bp):
        if b == 0 and counts[0] > 0:
            ansmod[v] = 0
            counts[0] -= 1
elif bp.count(1) <= counts[0]:
    # 3を割り当てる
    for v, b in enumerate(bp):
        if b == 1 and counts[0] > 0:
            ansmod[v] = 0
            counts[0] -= 1
else:
    # 違う方に違うのを割り当てる
    for v, b in enumerate(bp):
        if b == 0 and counts[1] > 0:
            ansmod[v] = 1
            counts[1] -= 1
        if b == 1 and counts[2] > 0:
            ansmod[v] = 2
            counts[2] -= 1
# 残りに余ってるのを割り当てる
for v in range(N):
    if ansmod[v] < 0:
        for i in range(3):
            if counts[i] > 0:
                ansmod[v] = i
                counts[i] -= 1
                break

ans = []
M = [3, 1, 2]
for a in ansmod:
    ans.append(M[a])
    M[a] += 3
print(*ans)
