from collections import deque
q=deque()
def MI(): return map(int, input().split())
N,M=MI()
g=[[] for _ in range(N+1)]
for _ in range(M):
  a,b=MI()
  g[a].append(b)
  g[b].append(a)
check=[0]*(N+1)
check[1]=1
ans=[0]*(N+1)
q.append(1)
while len(q)>0:
  v=q.popleft()
  for u in g[v]:
    if check[u]==0:
      check[u]=1
      ans[u]=v
      q.append(u)
print('Yes')
for i in range(2,N+1):
  print(ans[i])
