from collections import deque
from itertools import product


def bfs(x, y):
    dist = [[10 ** 9] * w for _ in range(h)]
    dist[y][x] = 0
    que = deque([(x, y)])
    near = list(product(range(-2, 3), repeat=2))

    while len(que) > 0:
        x, y = que.popleft()
        if (x, y) == (Dw - 1, Dh - 1):
            return dist[y][x]

        for dx, dy in near:
            cnt = (abs(dx) + abs(dy) >= 2)
            i, j = x + dx, y + dy
            if (0 <= i < w and 0 <= j < h and
                    dist[j][i] > dist[y][x] + cnt and s[j][i] == '.'):
                dist[j][i] = dist[y][x] + cnt
                if cnt == 0:
                    que.appendleft((i, j))
                elif cnt == 1:
                    que.append((i, j))
    else:
        return -1


h, w = map(int, input().split())
Ch, Cw = map(int, input().split())
Dh, Dw = map(int, input().split())
s = [input() for _ in range(h)]

print(bfs(Cw - 1, Ch - 1))
