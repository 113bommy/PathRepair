import sys
input=lambda: sys.stdin.readline().rstrip()
n=int(input())
A=[int(i) for i in input().split()]
edge=[[] for i in range(n)]
for i in range(n-1):
  a,b=map(int,input().split())
  edge[a-1].append(b-1)
  edge[b-1].append(a-1)
Ans=[]
inf=10**6
Par=[inf]*n
Par[0]=-1
Deg=[0]*n
Deg[0]=0
Chk=[0]
while Chk:
  c=Chk.pop()
  for next in edge[c]:
    if Par[next]==inf:
      Par[next]=c
      Deg[next]+=1
      Chk.append(next)
 
from collections import deque
TS=list(v for v in range(n) if Deg[v]==0)
D=deque(TS)
while D:
  v=D.popleft()
  for t in edge[v]:
    if t!=Par[v]:
      Deg[t]-=1
      if Deg[t]==0:
        D.append(t)
        TS.append(t)
 
C=[0]*n
for i in reversed(range(n)):
  v=TS[i]
  if A[v]==1:
    C[v]+=1
  else:
    C[v]-=1
  if Par[v]!=-1:
    C[Par[v]]+=max(0,C[v])
 
D=[0]*n
for i in range(n):
  v=TS[i]
  cur=max(0,D[v])
  for g in edge[v]:
    if g!=Par[v]:
      cur+=max(0,C[g])
  if A[v]==1:
    cur+=1
  else:
    cur-=1
  for g in edge[v]:
    if g!=Par[v]:
      D[g]+=cur-max(0,C[g])
 
Ans=[0]*n
for i in range(n):
  Ans[i]=C[i]+max(0,D[i])
print(*Ans)