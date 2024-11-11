import sys
from collections import deque
input = sys.stdin.readline
inf = 10**8
DX = (-1, 0, 1, 0, -1, -1, 1, 1)
DY = (0, 1, 0, -1, -1, 1, -1, 1)
DX = DX[:4]
DY = DY[:4]


H, W, K = map(int, input().split())
grid = [input().rstrip() for _ in range(H)]


dist = [[inf]*W for _ in range(H)]
node = deque()
for i in range(H):
    for j in range(W):
        if grid[i][j] == "S":
            node.append((i, j))
            dist[i][j] = 0

# まず一回普通にBFS
memo = []
while node:
    x, y = node.popleft()
    memo.append((x, y))
    d = dist[x][y]
    if d >= K:
        continue
    for dx, dy in zip(DX, DY):
        nx = x + dx
        ny = y + dy
        if nx < 0 or ny < 0 or nx >= H or ny >= W:
            continue
        if grid[nx][ny] == "#":
            continue
        if dist[nx][ny] > d + 1:
            dist[nx][ny] = d + 1
            node.append((nx, ny))


ans = inf
for x, y in memo:
    d = min(x, y, H - x - 1, W - y - 1)
    ans = min(ans, 1 + (d + K - 1) // K)
print(ans)