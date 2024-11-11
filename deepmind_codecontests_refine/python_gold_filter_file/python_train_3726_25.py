import itertools

N = int(input())
XY = [tuple(map(int,input().split())) for _ in range(N)]

def get_circle_center_and_radius(x1, y1, x2, y2, x3, y3):
  d = 2 * ((y1 - y3) * (x1 - x2) - (y1 - y2) * (x1 - x3))
  x = ((y1 - y3) * (y1 ** 2 - y2 ** 2 + x1 ** 2 - x2 ** 2) - (y1 - y2) * (y1 ** 2 - y3 ** 2 + x1 ** 2 - x3 ** 2)) / d
  y = ((x1 - x3) * (x1 ** 2 - x2 ** 2 + y1 ** 2 - y2 ** 2) - (x1 - x2) * (x1 ** 2 - x3 ** 2 + y1 ** 2 - y3 ** 2)) / -d
  r = ((x - x1) ** 2 + (y - y1) ** 2) ** 0.5
  return x, y, r

def check_line(x1,y1,x2,y2,x3,y3):
  if x1 == x2 == x3:
    return True
  elif y1 == y2 == y3:
    return True
  elif (y2-y1)*(x3-x1) == (y3-y1)*(x2-x1):
    return True
  else:
    return False

def check_r(x,y,r):
  res = True
  for i in range(N):
    x1,y1 = XY[i]
    if ((x-x1)**2+(y-y1)**2)**0.5 > r:
      res = False
      break
  return res

mnr = float('inf')
for i in range(N-1):
  for j in range(i+1,N):
    x1,y1 = XY[i]
    x2,y2 = XY[j]
    x = (x1+x2)/2
    y = (y1+y2)/2
    r = (((x2-x1)**2+(y2-y1)**2)**0.5)/2
    if check_r(x,y,r) and mnr > r:
      mnr = r    

for i,j,k in list(itertools.combinations(range(N),3)):
  x1,y1 = XY[i]
  x2,y2 = XY[j]
  x3,y3 = XY[k]
  if check_line(x1,y1,x2,y2,x3,y3):
    continue
  x,y,r = get_circle_center_and_radius(x1,y1,x2,y2,x3,y3)
  if check_r(x,y,r) and mnr > r:
    mnr = r

print(mnr)
