import math

t = int(input())

for _ in range(t):
  n = int(input())
  
  angle = math.pi / (2*n)
  e2e = 1 / (math.tan(angle))
  c2c = 1 / (math.sin(angle))

#   print('angle = %.9f and e2e = %.9f and c2c = %.9f' % (angle, e2e, c2c))

  if n % 2 == 1:
    print('%.10f' % c2c)
  else:
    print('%.10f' % e2e)