from collections import deque
h,w = map(int,input().split())
ch,cw = map(int,input().split())
dh,dw = map(int,input().split())
path = [[10**10]*w for i in range(h)]
maze = []
for _ in range(h):
  s = input()
  maze.append(s)

walk = [(0,1),(1,0),(-1,0),(0,-1)]
warp = [(i,j) for i in range(-2,3) for j in range(-2,3) if (i,j) not in [(0,0)]+walk]
Q = deque()
path[ch-1][cw-1]=0
Q.append((ch-1,cw-1,0))
while Q:
  hi,wi,c = Q.popleft()
  for i,j in walk:
    nh = i + hi
    nw = j + wi
    if 0<=nh<h and 0<=nw<w and maze[nh][nw]=='.' and path[nh][nw]>c:
      path[nh][nw] = c
      Q.appendleft((nh,nw,c))
  for i,j in warp:
    nh = i + hi
    nw = j + wi
    if 0<=nh<h and 0<=nw<w and maze[nh][nw]=='.' and path[nh][nw]>c+1:
      path[nh][nw] = c+1
      Q.append((nh,nw,c+1))
print(path[dh-1][dw-1] if path[dh-1][dw-1]<10**10 else -1)