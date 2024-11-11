n,m = map(int,input().split())
graph = {i:[] for i in range(1,n+1)}

for _ in range(m):
  a,b = map(int,input().split())
  graph[a].append(b)
  graph[b].append(a)
  
bridge = set([])

ans = 0
while 1:
  count = 0
  for i in range(1,n+1):
    if len(graph[i]) == 1:
      count += 1
      a = graph[i][0]
      graph[a].remove(i)
      graph[i] = []
  ans += count
  if count == 0:
    break
  else:
    count = 0
print(ans)
  

