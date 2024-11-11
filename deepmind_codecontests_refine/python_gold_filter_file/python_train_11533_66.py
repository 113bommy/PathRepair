
from collections import deque

H, W = map(int, input().split())
C_h, C_w = map(int, input().split())
D_h, D_w = map(int, input().split())
X = [input() for _ in range(H)]

inf = 10 ** 9
dist = [[inf] * W for _ in range(H)]
dist[C_h - 1][C_w - 1] = 0
q = deque()
q.append((C_h - 1, C_w - 1))


while q:
    u, v = q.popleft()
    for i, j in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
        if (0 <= u + i < H and 0 <= v + j < W
                and X[u + i][v + j] == "."
                and dist[u + i][v + j] > dist[u][v]):
            dist[u + i][v + j] = dist[u][v]
            q.appendleft((u + i, v + j))

    for i in range(-2, 3):
        for j in range(-2, 3):
            if (0 <= u + i < H and 0 <= v + j < W
                    and X[u + i][v + j] == "."
                    and dist[u + i][v + j] > dist[u][v] + 1):
                dist[u + i][v + j] = dist[u][v] + 1
                q.append((u + i, v + j))

if dist[D_h - 1][D_w - 1] < inf:
    print(dist[D_h - 1][D_w - 1])
else:
    print(-1)
