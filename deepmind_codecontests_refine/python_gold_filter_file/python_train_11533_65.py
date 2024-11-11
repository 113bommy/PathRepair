import heapq

H, W = map(lambda x: int(x)+4, input().split())
Ch, Cw = map(int, input().split())
Dh, Dw = map(int, input().split())

grid = '#' * W * 2
for _ in range(H-4):
  grid += '##' + input() + '##'
grid += '#' * W * 2

move_list = []
for i in range(5):
  for j in range(5):
    if (i, j) == (2, 2):
      continue
    elif (i, j) == (1, 2) or (i, j) == (2, 1) or (i, j) == (2, 3) or (i, j) == (3, 2):
      move_list.append((0, i-2 + W*(j-2)))
    else:
      move_list.append((1, i-2 + W*(j-2)))

def dijkstra(s):
  hq = [(0, s)]
  heapq.heapify(hq)
  cost = [float("inf")] * (H*W)
  cost[s] = 0
  while hq:
    c, v = heapq.heappop(hq)
    if c > cost[v]:
      continue
    for dc, dv in move_list:
      w = v + dv
      tmp = cost[v] + dc
      if grid[w] == "#":
        continue
      if tmp < cost[w]:
        cost[w] = tmp
        heapq.heappush(hq, (tmp, w))
  return cost

ans = dijkstra( (Ch+1)*W + Cw+1 )[(Dh+1)*W + Dw+1]

if ans == float("inf"):
  print(-1)
else:
  print(ans)