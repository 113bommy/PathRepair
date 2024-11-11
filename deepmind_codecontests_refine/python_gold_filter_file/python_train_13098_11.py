
import heapq
n, m, s, t = map(int, input().split())
money = 10**15 
graph = [[] for _ in range(n)]

for _ in range(m):
  u, v, a, b = map(int, input().split())
  u -= 1
  v -= 1 
  graph[u] += [[v, a, b]]
  graph[v] += [[u, a, b]]

def dijkstra(s, y):
  dist = [float('inf')]*n 
  dist[s] = 0
  q = [[0, s]]
  heapq.heapify(q)
  while q:
    cost, u = heapq.heappop(q)
    for v, yen, snuuk in graph[u]:
      if y:
        if dist[u] + yen < dist[v]:
          dist[v] = dist[u] + yen 
          heapq.heappush(q, [dist[v], v])
      else:
        if dist[u] + snuuk < dist[v]:
          dist[v] = dist[u] + snuuk 
          heapq.heappush(q, [dist[v], v])
  return dist

y_result = dijkstra(s-1, True)
s_result = dijkstra(t-1, False)

result = [y_result[i]+s_result[i] for i in range(n)]

for i in range(n-1, 0, -1):
  result[i-1] = min(result[i], result[i-1])

for i in range(n):
  print(money-result[i])
