N=int(input())
import copy
def warshall_floyd(N):
  d=[list(map(int,input().split())) for i in range(N)]
  D=copy.deepcopy(d)
  for k in range(N):
    for i in range(N):
      for j in range(N):
        d[i][j]=min(d[i][j],d[i][k]+d[k][j])
  if d==D:
    return d
  else:
    return -1
  
E=warshall_floyd(N)
if E==-1:
  print(-1)
  exit()
  
for k in range(N):
  for i in range(N):
    for j in range(N):
      if E[i][j]!=0 and E[i][k]!=0 and E[k][j]!=0:
        if E[i][j]==E[i][k]+E[k][j]:
          E[i][j]=0       
ans=0
for i in range(N):
  ans+=sum(E[i]) 
print(ans//2)