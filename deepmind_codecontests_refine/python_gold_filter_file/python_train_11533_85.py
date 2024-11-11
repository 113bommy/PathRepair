INF=10**6
f=lambda:map(int,input().split())
h,w=f()
ch,cw=f()
dh,dw=f()
g=[input() for _ in range(h)]
d=[[INF]*w for _ in range(h)]
d[ch-1][cw-1]=0
from collections import *
q=deque([(0,ch-1,cw-1)])
while q:
  td,tx,ty=q.popleft()
  if d[tx][ty]<td: continue
  for dx,dy in [(1,0),(0,1),(-1,0),(0,-1)]:
    nx,ny=tx+dx,ty+dy
    if 0<=nx<h and 0<=ny<w and g[nx][ny]=='.' and d[nx][ny]>td:
      d[nx][ny]=td
      q.appendleft((td,nx,ny))
  for dx in range(-2,3):
    for dy in range(-2,3):
      nx,ny=tx+dx,ty+dy
      if 0<=nx<h and 0<=ny<w and g[nx][ny]=='.' and d[nx][ny]>td+1:
        d[nx][ny]=td+1
        q.append((td+1,nx,ny))
a=d[dh-1][dw-1]
print([-1,a][a<INF])