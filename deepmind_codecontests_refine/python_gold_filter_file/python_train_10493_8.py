import math
a, b, x = map(int, input().split())
if x < (a*a*b/2):
  print(math.degrees(math.atan((a*b*b)/(2*x))))
else:
  print(math.degrees(math.atan((2*b -2*x/(a**2))/a)))