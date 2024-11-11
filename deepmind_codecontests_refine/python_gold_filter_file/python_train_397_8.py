h,w,k=map(int,input().split())
a=[input() for _ in range(h)]
s=(0,0)
for i in range(h*w):
    x,y=divmod(i,w)
    if a[x][y]=='S':
        s=(x,y)
        break
from collections import deque
todo=deque([s])
inf=float('inf')
seen=[[inf]*w for _ in range(h)]
seen[s[0]][s[1]]=0
while todo:
    (x,y)=todo.popleft()
    for dx,dy in ((0,1),(0,-1),(1,0),(-1,0)):
        nx=x+dx
        ny=y+dy
        if 0<=nx<h and 0<=ny<w and a[nx][ny]!='#' and seen[nx][ny]>seen[x][y]+1:
            seen[nx][ny]=seen[x][y]+1
            if seen[nx][ny]<k:todo.append((nx,ny))
ans=h*w
for i in range(h*w):
    x,y=divmod(i,w)
    if seen[x][y]==inf:continue
    tmp=min(x,y,h-x-1,w-y-1)
    tmp=(tmp+k-1)//k
    ans=min(ans,tmp)
print(ans+1)