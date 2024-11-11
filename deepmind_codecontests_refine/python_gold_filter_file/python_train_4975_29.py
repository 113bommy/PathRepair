from collections import deque

N = int(input())
tree = [[] for i in range(N)]
for i in range(N-1):
  a, b = map(int, input().split())
  tree[a-1].append(b-1)
  tree[b-1].append(a-1)

d = deque([[0, -1]])
dist = [0] * N
while d:
  node, par = d.pop()
  children = tree[node]
  for child in children:
    if child == par:
      continue
    dist[child] = (dist[node] + 1) % 2
    d.appendleft([child, node])

count0 = dist.count(0)
count1 = N - count0
s = [set(), set(), set()]
for i in range(1, N+1):
  s[i%3].add(i)
if count0 > N//3:
  if count1 > N//3:
    for i in range(N):
      if dist[i]:
        if s[2]:
          dist[i] = s[2].pop()
        else:
          dist[i] = s[0].pop()
      else:
        if s[1]:
          dist[i] = s[1].pop()
        else:
          dist[i] = s[0].pop()
  else:
    for i in range(N):
      if dist[i]:
        dist[i] = s[0].pop()
      else:
        if s[2]:
          dist[i] = s[2].pop()
        elif s[1]:
          dist[i] = s[1].pop()
        else:
          dist[i] = s[0].pop()
else:
  for i in range(N):
    if dist[i]:
      if s[2]:
        dist[i] = s[2].pop()
      elif s[1]:
        dist[i] = s[1].pop()
      else:
        dist[i] = s[0].pop()
    else:
      dist[i] = s[0].pop()

print(*dist)