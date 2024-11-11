from heapq import heappush, heappop
v,e,r = map(int,input().split())
edges=[[] for i in range(v)]
d = [float('INF')]*v

for i in range(e):
  s,t,c = map(int,input().split())
  edges[s].append([t,c])

que = []
heappush(que,(0,r))
d[r] = 0

while que:
  c, u = heappop(que)
  for v, s in edges[u]:
    if d[v] > s + c:
      d[v] = s + c
      heappush(que,(d[v],v))
for i in d:
  if i == float('inf'):
    print('INF')
  else:
    print(i)
