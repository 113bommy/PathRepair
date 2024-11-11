n, m = map(int, input().split())
adj = [[] for _ in range(n)]
for _ in range(m):
  x, y, z = map(int, input().split())
  adj[x-1].append(y-1)
  adj[y-1].append(x-1)
opn = [True] * n
count = 0
for i in range(n):
  if opn[i]:
    count += 1
    opn[i] = False
    stack = [i]
    while stack:
      u = stack.pop()
      for v in adj[u]:
        if opn[v]:
          stack.append(v)
          opn[v] = False
print(count)