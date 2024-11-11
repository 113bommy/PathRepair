n, m = map(int, input().split())
g = [[] for i in range(n)]
for i in range(m):
  u,v,z=map(int, input().split())
  g[u-1].append((u-1, v-1, z))
  g[v-1].append((v-1,u-1,z))
count = 0
renketu_list = [-1]*n
stack = []
for i in range(n):
  if renketu_list[i] == -1:
    count += 1
    renketu_list[i] = count
    while len(g[i]) > 0:
      stack.append(g[i].pop())
    while len(stack) > 0:
      u,v,z=stack.pop()
      if renketu_list[v] == -1:
        renketu_list[v] = count
        while len(g[v])>0:
          stack.append(g[v].pop())

print(count)
