n = int(input())
g = [[] for _ in range(n)]

for _ in range(n-1):
    a, b = map(lambda x: int(x)-1, input().split())
    g[a].append(b)
    g[b].append(a)

from collections import deque


def solve(n, g):
    visited = []
    cols = []
    
    for _ in range(n):
        visited.append(0)
        cols.append(None)

    visited[0] = 1
    cnt_A = 0
    cnt_B = 0

    nodes = deque([(0, 0)])

    while nodes:
        node, col = nodes.popleft()

        cols[node] = col
        if col == 0: cnt_A += 1
        else: cnt_B += 1

        for nb in g[node]:
            if not visited[nb]:
                nodes.append((nb, 0 if col == 1 else 1))
                visited[nb] = 1
    
    count = 0
    cnts = [cnt_A, cnt_B]
    #print(cnts)
    #print(cols)
    for col, node in zip(cols, range(n)):
        other_cnt = cnts[0 if col == 1 else 1]
        count += max(0, other_cnt - len(g[node]))
        #print(count)
    
    return count // 2

print(solve(n, g))