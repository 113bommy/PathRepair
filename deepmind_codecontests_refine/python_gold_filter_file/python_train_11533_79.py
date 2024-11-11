INF=10**6
f=lambda:map(int,input().split())
h,w=f()
ch,cw=f()
ch-=1
cw-=1
dh,dw=f()
dh-=1
dw-=1
g=[input() for _ in range(h)]
from collections import *
def grid_01_bfs(x,y):
  d=[[INF]*w for _ in range(h)]
  d[x][y]=0
  q=deque([(0,x,y)])
  while q:
    td,tx,ty=q.popleft()
    if d[tx][ty]<td: continue
    for dx,dy in [(1,0),(0,1),(-1,0),(0,-1)]:
      nx,ny=tx+dx,ty+dy
      if 0<=nx<h and 0<=ny<w and g[nx][ny]=='.' and d[nx][ny]>td:
        d[nx][ny]=td
        q.appendleft((d[nx][ny],nx,ny))
    for dx in range(-2,3):
      for dy in range(-2,3):
        nx,ny=tx+dx,ty+dy
        if 0<=nx<h and 0<=ny<w and g[nx][ny]=='.' and d[nx][ny]>td+1:
          d[nx][ny]=td+1
          q.append((d[nx][ny],nx,ny))
  return d
a=grid_01_bfs(ch,cw)[dh][dw]
print([-1,a][a<INF])