import sys
import math
from collections import deque,Counter
from sys import stdin

#sys.setrecursionlimit(10**7)

int1=lambda x: int(x)-1
stinput=lambda :stdin.readline()[:-1]
ii=lambda :int(stinput())
mi=lambda :map(int, stdin.readline().split())
li=lambda :list(mi())
mi1=lambda :map(int1, stdin.readline().split())
li1=lambda :list(mi1())
mis=lambda :map(str, stdin.readline().split())

pr=print
rg=range

from collections import defaultdict

mod=10**9+7
Mod=998244353
INF=10**18
ans=0

t=ii()
for _ in range(t):
  h,w=mi()
  s=[['.']*w for i in range(h)]
  sx,sy=0,0
  for i in range(h):
    t=stinput()
    for j in range(w):
      s[i][j]=t[j]
      if t[j]=='L':
        sx,sy=i,j
  d=deque()
  d.append((sx,sy))
  dxdy=[(0,1),(1,0),(-1,0),(0,-1)]
  while d:
    x,y=d.pop()
    for dx,dy in dxdy:
      nx,ny=x+dx,y+dy
      if 0<=nx<h and 0<=ny<w and s[nx][ny]=='.':
        cnt=0
        for ddx,ddy in dxdy:
          nnx,nny=nx+ddx,ny+ddy
          if 0<=nnx<h and 0<=nny<w and s[nnx][nny]=='.':
            cnt+=1
        if cnt<=1:
          s[nx][ny]='+'
          d.append((nx,ny))
  for i in s:
    print(''.join(i))