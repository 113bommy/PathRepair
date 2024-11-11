N, M = map(int, input().split())
node =[[] for _ in range(N)]

for _ in range(M):
  x, y = map(int, input().split())
  node[x-1].append(y-1)
  node[y-1].append(x-1)

ct = [-1]*N

i = 0
stack = []
ct[0] = 0
stack.append(0)
while len(stack) != 0:
  v = stack.pop(0)
  for e in node[v]:
    if ct[e] == -1:
      ct[e] = v
      stack.append(e)

print('Yes')
for i in range(1,N):
  print(ct[i]+1)