from math import atan, degrees
a,b,x = map(int, input().split())

if x/a >= a*b/2:
  print(degrees(atan((b-x/(a**2))*2/a)))
else:
  print(90 - degrees(atan(2*x/(a*(b**2)))))