# coding: UTF-8
from collections import deque
n,m = map(int,input().split())
link = [[] for _ in range(n)]
part = [-1 for _ in range(n)]
for _ in range(m):
  u,v = map(int,input().split())
  link[u].append(v)
  link[v].append(u)

searched = set()
queue = deque()
pindex = 0
for u in range(n):
  if u not in searched:
    queue.append(u)
    pindex += 1
    searched.add(u)
    while queue:
      v = queue.popleft()
      part[v] = pindex
      for w in link[v]:
        if w not in searched:
          part[w] = pindex
          queue.append(w)
          searched.add(w)

q = int(input())
answers = []
for _ in range(q):
  s,t = map(int,input().split())
  if part[s] == part[t]:
    answers.append("yes")
  else:
    answers.append("no")

for answer in answers:
  print(answer)
