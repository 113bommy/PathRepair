from collections import deque
h,w=map(int,input().split())
ch,cw=map(int,input().split())
dh,dw=map(int,input().split())
s=[list(input()) for i in range(h)]

#幅優先で解く。
dx=[1,0,-1,0]
dy=[0,1,0,-1]
def bfs():
  maze=[[-1]*w for i in range(h)]
  maze[ch-1][cw-1]=0
  qu=deque([])
  qu.append((cw-1,ch-1))
  magic=0
  
  while qu:
    x,y=qu.popleft()
    for i in range(x-2,x+3):
      for j in range(y-2,y+3):
        nx=i
        ny=j
        if 0<=nx<=w-1 and 0<=ny<=h-1 and s[ny][nx]=="." and (maze[ny][nx]==-1 or maze[ny][nx]>maze[y][x]+1):
          qu.append((nx,ny))
          maze[ny][nx]=maze[y][x]+1
    for i in range(4):
      nx=dx[i]+x
      ny=dy[i]+y
      
      if 0<=nx<=w-1 and 0<=ny<=h-1 and s[ny][nx]=="." and (maze[ny][nx]==-1 or maze[ny][nx]>maze[y][x]):
        qu.appendleft((nx,ny))
        maze[ny][nx]=maze[y][x]
  return maze
    
maze = bfs()
print(maze[dh-1][dw-1])