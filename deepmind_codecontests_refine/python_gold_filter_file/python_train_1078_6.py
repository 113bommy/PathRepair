import math
n = int(input())
if n<=2:
  print(-1)
else:
  print(210*((10**(n-1)+209)//210))