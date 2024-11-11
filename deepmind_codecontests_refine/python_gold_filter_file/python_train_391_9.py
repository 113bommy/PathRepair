import sys
sys.setrecursionlimit(10**5)
N,u,v=map(int,input().split())

du,dv=[0]*-~N,[0]*-~N
T=[list() for i in range(-~N)]

def dfs(p,t,v,d):
  d[v]=t
  for i in T[v]:
    if i!=p:
      dfs(v,t+1,i,d)

for i in range(N-1):
  a,b=map(int,input().split())
  T[a].append(b)
  T[b].append(a)

dfs(0,0,u,du)
dfs(0,0,v,dv)

c=0
for i in range(1,-~N):
  if len(T[i])==1 and i!=v:
    if du[i]<dv[i]:
      c=max(c,~-dv[i])

print(c)

