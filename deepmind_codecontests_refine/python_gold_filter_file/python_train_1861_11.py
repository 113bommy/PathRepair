import math
x,y,r = 0,0,90
while True:
  m,n = map(int,input().split(','))
  if (m,n) == (0,0):
    break
  y += m * math.sin(math.radians(r))
  x += m * math.cos(math.radians(r))
  r -= n
print(int(x))
print(int(y))