f=lambda:map(int,input().split())
n,m=f()
g = [[] for _ in range(n)]
for _ in range(m):
  a,b=f()
  g[a-1].append(b-1)
  g[b-1].append(a-1)
p = [0]*n
from collections import deque
q = deque([0])

while q:
  v = q.popleft()
  for c in g[v]:
    if p[c]<1:p[c]=v+1;q.append(c)
if 0 in p: print('No')
else: print('Yes',*p[1:],sep='\n')