def Warshall_Floyd(edges,N):
  import copy
  d=copy.deepcopy(edges)
  for k in range(N):
    for i in range(N):
      for j in range(N):
        d[i][j]=min(d[i][j],d[i][k]+d[k][j])
  return d

import sys
N=int(input())
A=[list(map(int,input().split())) for i in range(N)]
B=Warshall_Floyd(A,N)
if A!=B:
  print(-1)
  sys.exit()

ans=0
for i in range(N):
  for j in range(i):
    need=1
    for k in range(N):
      if k!=i and k!=j:
        if A[i][j]==A[i][k]+A[k][j]: need=0
    ans+=need*A[i][j]
print(ans)