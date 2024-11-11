#!/usr/bin/env python3

import collections

h,w=map(int,input().split())
sy,sx=map(int,input().split())
gy,gx=map(int,input().split())
board=[['#']*(w+2)]+[list('#'+input()+'#') for _ in range(h)]+[['#']*(w+2)]
checked=[[False]*(w+1) for _ in range(h+1)]
checked[sy][sx]=True
q=collections.deque()
q.append((sy,sx))
ans=0
while 1:
  cur_pos=[]
  while len(q)!=0:
    y,x=q.popleft()
    cur_pos.append((y,x))
    for dy,dx in [[-1,0],[1,0],[0,-1],[0,1]]:
      if 1<=y+dy<=h and 1<=x+dx<=w and board[y+dy][x+dx]=='.' and checked[y+dy][x+dx]==False:
        checked[y+dy][x+dx]=True
        q.append((y+dy,x+dx))
  if checked[gy][gx]==True:
    print(ans)
    exit()
  if len(cur_pos)==0:
    print(-1)
    exit()
  ans+=1
  for y,x in cur_pos:
    for dy in range(-2,3):
      for dx in range(-2,3):
        if dy==0 and dx==0:
          continue
        if 1<=y+dy<=h and 1<=x+dx<=w and board[y+dy][x+dx]=='.' and checked[y+dy][x+dx]==False:
          checked[y+dy][x+dx]=True
          q.append((y+dy,x+dx))