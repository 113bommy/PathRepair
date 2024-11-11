from collections import deque

n = int(input())
rlst = [None] * (n + 1)
for _ in range(n):
  lst = list(map(int, input().split()))
  r = lst[0]
  lst = lst[2:]
  rlst[r] = lst

p = int(input())

for _ in range(p):
  s, d, v = map(int, input().split())
  visited = [False] * (n + 1)
  visited[s] = True
  que = deque()
  que.append((s, 0))
  while que:
    node, dist = que.popleft()
    if node == d:
      if dist < v:
        print(dist + 1)
      else:
        print("NA")
      break
    for to in rlst[node]:
      if not visited[to]:
        que.append((to, dist + 1))
        visited[to] = True
  else:
    print("NA")
