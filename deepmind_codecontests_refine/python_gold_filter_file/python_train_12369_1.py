import sys
from collections import deque
input = sys.stdin.readline
n,m = map(int,input().split())
ab = [list(map(int,input().split())) for i in range(n-1+m)]
tree_go = [[] for i in range(n+1)]
tree_come = [[] for i in range(n+1)]
excess = [0 for i in range(n+1)]
for a,b in ab:
  tree_go[a].append(b)
  tree_come[b].append(a)
for i in range(1,n+1):
  if tree_come[i] == []:
    root = i
  if len(tree_come[i]) >= 2:
    excess[i] = len(tree_come[i])-1
que = deque([(root,0)])
parent = [0 for i in range(n+1)]
visited = [0 for i in range(n+1)]
while que:
  x,px = que.popleft()
  parent[x] = px
  if excess[x] >= 1:
    excess[x] -= 1
    continue
  for y in tree_go[x]:
    que.append((y,x))
print(*parent[1:],sep="\n")
