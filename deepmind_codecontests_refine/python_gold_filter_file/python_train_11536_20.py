from collections import defaultdict
import sys
sys.setrecursionlimit(1000000)
input = sys.stdin.readline

n, m = list(map(int, input().split()))

if m%2==1:
  print(-1)
  exit()

graph = defaultdict(set)
grapht = defaultdict(set)
for i in range(m):
  a, b = list(map(int, input().split()))
  a -= 1
  b -= 1
  graph[a].add(b)
  graph[b].add(a)
  grapht[a].add(b)
  grapht[b].add(a)

graph2 = defaultdict(set)
visited = [0 for i in range(n)]
num = [1 for i in range(n)]

def dfs(x):
  visited[x] = 1

  for nx in graph[x]:
    if not visited[nx]:
      dfs(nx)

  t = set()
  if num[x]==1 and len(grapht[x])%2==0:
    for e in grapht[x]:
      graph2[x].add(e)
      t.add(e)
  elif num[x]==-1 and len(grapht[x])%2==0:
    for j, e in enumerate(grapht[x]):
      if j==len(grapht[x])-1:
        graph2[e].add(x)
        num[e] *= -1
      else:
        graph2[x].add(e)
      t.add(e)
  elif num[x]==1 and len(grapht[x])%2==1:
    for j, e in enumerate(grapht[x]):
      if j==len(grapht[x])-1:
        graph2[e].add(x)
        num[e] *= -1
      else:
        graph2[x].add(e)
      t.add(e)
  elif num[x]==-1 and len(grapht[x])%2==1:
    for e in grapht[x]:
      graph2[x].add(e)
      t.add(e)
  for e in t:
    grapht[x].remove(e)
    grapht[e].remove(x)

dfs(0)

for i in range(n):
  for e in graph2[i]:
    print(i+1, e+1)
