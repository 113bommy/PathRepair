def scm(x1, y1, x2, y2, x3, y3):
  return (x2 - x1) * (x3 - x1) + (y2 - y1) * (y3 - y1)
  
def scma(a):
  x = abs((a[4] - a[0]) * (a[2] - a[0]) + (a[3] - a[1]) * (a[5] - a[1]))
  y = abs((a[4] - a[2]) * (a[0] - a[2]) + (a[1] - a[3]) * (a[5] - a[3]))
  z = abs((a[2] - a[4]) * (a[0] - a[4]) + (a[3] - a[5]) * (a[1] - a[5]))
#  print(x, y,z)
  if (x ==0 and ((y ==0) or (z ==0))) or ((y ==0) and (z == 0)):
    return 1
  else: 
    return min(x,y,z)
  
pair = [1, -2, 1]
f = False
p = [int(i) for i in input().split()]
#print(scma(p))
if scma(p) == 0:
  print('RIGHT')
else:
  for i in range(6):
    for j in pair:
      p[i] += j
      if scma(p) == 0:
        f = True    
  if f:
    print('ALMOST')
  else:
    print('NEITHER')