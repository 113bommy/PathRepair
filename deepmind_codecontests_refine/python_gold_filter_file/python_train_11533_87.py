H,W = map(int,input().split())

start = tuple(map(lambda x:x - 1, map(int,input().split())))
goal = tuple(map(lambda x:x - 1, map(int,input().split())))

S = [input() for i in range(H)]

from collections import deque
q = deque([])

# 頂点, コスト
q.append([start[0], start[1], 0])
INF = 10 ** 10
cost = [[INF] * W for i in range(H)]

while q:
  y,x,c = q.popleft()
  if S[y][x] == "#":
    continue
  if cost[y][x] <= c:
    continue
  cost[y][x] = c
  for i in range(-2,3):
    for j in range(-2,3):
      if i == 0 and j == 0:
        continue
      if 0 <= y + i < H and 0 <= x + j < W:
        if abs(i) + abs(j) == 1:
          q.appendleft([y + i, x + j, c])
        else:
          q.append([y + i, x + j, c + 1])

if cost[goal[0]][goal[1]] == INF:
  print(-1)
else:
  print(cost[goal[0]][goal[1]])
