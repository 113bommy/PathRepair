from collections import *
from itertools import *
h, w = map(int, input().split())
maze = [input() for _ in range(h)]
dest = [(1, 0), (-1, 0), (0, 1), (0, -1)]
score = 0

for sx, sy in product(range(w), range(h)):
  if maze[sy][sx] == '#':
    continue
  r = [[-1] * w for _ in range(h)]
  r[sy][sx] = 0
  queue = deque([(sx, sy)])
  while queue:
    x, y = queue.popleft()
    for dx, dy in dest:
      nx, ny = x + dx, y + dy
      if not (0 <= nx < w and 0 <= ny < h):
        continue
      if maze[ny][nx] == '#' or r[ny][nx] != -1:
        continue
      r[ny][nx] = r[y][x] + 1
      queue.append((nx, ny))
      score = max(score, r[ny][nx])
print(score)