from collections import deque
import bisect

INF = float("inf")

N,M = map(int,input().split())

xtic = {0,-INF,INF}
ytic = {0,-INF,INF}

hor = []
for _ in range(N):
  a,b,c = map(int,input().split())
  hor.append((c,a,b))
  xtic.add(a)
  xtic.add(b)
  ytic.add(c)
  
ver = []
for _ in range(M):
  d,e,f = map(int,input().split())
  ver.append((d,e,f))
  xtic.add(d)
  ytic.add(e)
  ytic.add(f)

xtic = list(xtic)
ytic = list(ytic)
xtic.sort()
ytic.sort()
xdic = {xtic[i]:i+1 for i in range(len(xtic))}
ydic = {ytic[i]:i+1 for i in range(len(ytic))}

gyaku_xdic = {xdic[k]:k for k in xdic}
gyaku_ydic = {ydic[k]:k for k in ydic}

hor.sort()
ver.sort()

hor_dic = {}
ver_dic = {}

now = None
for c,a,b in hor:
  c,a,b = ydic[c],xdic[a],xdic[b]
  if c != now:
    hor_dic[c] = (1<<b) - (1<<a)
  else:
    hor_dic[c] |= (1<<b) - (1<<a)
  now = c

now = None
for d,e,f in ver:
  d,e,f = xdic[d],ydic[e],ydic[f]
  if d != now:
    ver_dic[d] = (1<<f) - (1<<e)
  else:
    ver_dic[d] |= (1<<f) - (1<<e)
  now = d

def is_connected(x,y,dx,dy):
  if dx == 0:
    if dy > 0:
      if (hor_wall[y+1]>>x)&1:
        return False
      return True
    else:
      if (hor_wall[y]>>x)&1:
        return False
      return True
  else:
    if dx > 0:
      if (ver_wall[x+1]>>y)&1:
        return False
      return True
    else:
      if (ver_wall[x]>>y)&1:
        return False
      return True
      
def calc_area(x,y):
  X = gyaku_xdic[x+1] - gyaku_xdic[x]
  Y = gyaku_ydic[y+1] - gyaku_ydic[y]
  return X*Y

offset = [(1,0),(0,1),(-1,0),(0,-1)]
x0 = bisect.bisect(xtic,0)
y0 = bisect.bisect(ytic,0)
W,H = len(xtic)+1 ,len(ytic)+1

hor_wall = [0 for i in range(H)]
ver_wall = [0 for i in range(W)]

for k in hor_dic:
  hor_wall[k] = hor_dic[k]
for k in ver_dic:
  ver_wall[k] = ver_dic[k]

d = [[0 for i in range(W)] for j in range(H)]
d[y0][x0] = 1
q = deque([(x0,y0)])

area = 0

while q:
  x,y = q.pop()
  area += calc_area(x,y)
  for dx,dy in offset:
    nx,ny = x+dx,y+dy
    if 0<=nx<W and 0<=ny<H:
      if is_connected(x,y,dx,dy):
        if nx == 0 or ny == 0 or nx == W-1 or ny == H-1:
          print("INF")
          exit()
        if d[ny][nx] == 0:
          d[ny][nx] = 1
          q.append((nx,ny))

print(area)