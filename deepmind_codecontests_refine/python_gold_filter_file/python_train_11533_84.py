#写経
#16133681

import sys
input = lambda: sys.stdin.readline().rstrip()
h,w=map(int,input().split())
ch,cw=map(int,input().split())
ch-=1
cw-=1
stack=[(ch,cw)]
dh,dw=map(int,input().split())
dh-=1
dw-=1
b=[w*[-1]for _ in range(h)]
for i in range(h):
  for j,t in enumerate(input()):
    if t=="#":b[i][j]=10**10
b[ch][cw]=0
dxy=((-1,0),(1,0),(0,-1),(0,1))
for ans in range(10**6):
  for x,y in stack:
    b[x][y]=1
    if x==dh and y==dw:
      print(ans)
      exit()
    for dx,dy in dxy:
      if 0<=x+dx<h and 0<=y+dy<w:
        if b[x+dx][y+dy]==10**10:continue
        if b[x+dx][y+dy]==-1:
          stack.append((x+dx,y+dy))
          b[x+dx][y+dy]=1
  stackk=[]
  for x,y in stack:
    for xx in range(max(0,x-2),min(h,x+3)):
      for yy in range(max(0,y-2),min(w,y+3)):
        if b[xx][yy]==-1:stackk.append((xx,yy))
  stack=stackk
print(-1)