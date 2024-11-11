n=int(input())
a=[list(map(int,input().split()))for _ in range(n)]
calc=lambda u,v:min(u,v)*n+max(u,v)
edge=[[]for _ in range(n*n)]
for i in range(n):
  for j in range(1,n-1):
    u,v=calc(a[i][j-1]-1,i),calc(a[i][j]-1,i)
    edge[u].append(v)
from collections import deque
def find_loop(n,e):
  x=[0]*n
  d=deque()
  t=[]
  c=0
  for i in range(n):
    for j in e[i]:x[j]+=1
  for i in range(n):
    if x[i]==0:
      d.append(i)
      t.append(i)
      c+=1
  while d:
    i=d.popleft()
    for j in e[i]:
      x[j]-=1
      if x[j]==0:
        d.append(j)
        t.append(j)
        c+=1
  return t
d=find_loop(n*n,edge)
if len(d)!=n*n:exit(print(-1))
c=[1]*n*n
for i in d:
  for j in edge[i]:
    c[j]=c[i]+1
print(max(c))
