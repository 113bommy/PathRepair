def MI(): return map(int, input().split())
from collections import deque
def bfs(field,s):
  q=deque([(0,s)])
  MOVE=[(-1,0),(0,-1),(1,0),(0,1)]
  dist=[[-1]*W for i in range(H)]
  d,i,j=-1,-1,-1  
  while q:
    d,(i,j)=q.popleft()
    if dist[i][j]!=-1:
      continue
    dist[i][j]=d
    for di,dj in MOVE:
      ni=i+di
      nj=j+dj
      if not 0<=ni<H or not 0<=nj<W:
        continue
      if field[ni][nj]=='#':
        continue
      if dist[ni][nj]!=-1:
        continue
      q.append((d+1,(ni,nj)))
  return d,i,j
H,W=MI()
field=[input() for _ in range(H)]
ans=0
for i in range(H):
  for j in range(W):
    if field[i][j]=='.':
      d,i,j=bfs(field,(i,j))
      ans=max(ans,d)
print(ans)
