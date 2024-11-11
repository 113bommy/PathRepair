import sys
stdin = sys.stdin
sys.setrecursionlimit(10**6)
ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
nn = lambda: list(stdin.readline().split())
ns = lambda: stdin.readline().rstrip()

h,w = na()
ch,cw = na()
dh,dw = na()
ch,cw = ch-1,cw-1
dh,dw = dh-1,dw-1
s = []
for i in range(h):
  s.append(ns())

from collections import deque

g = [[10000000000]*w for i in range(h)]
g[ch][cw] = 0
d = deque([(ch,cw,0)])

while d:
  x,y,num = d.popleft()
  pq = [(-1,0),(0,1),(1,0),(0,-1)]
  for p,q in pq:
    if not (0<=x+p<h and 0<=y+q<w):
      continue
    u = s[x+p][y+q]
    if u == '.':
      if num < g[x+p][y+q]:
        g[x+p][y+q] = num
        d.appendleft((x+p,y+q,num))

  for i in range(-2,3):
    for j in range(-2,3):
      if not (0<=x+i<h and 0<=y+j<w):
        continue
      p = s[x+i][y+j]
      if p == '.':
        if num+1 < g[x+i][y+j]:
          g[x+i][y+j] = num+1
          d.append((x+i,y+j,num+1))

ans = g[dh][dw]

print('-1' if ans == 10000000000 else ans)