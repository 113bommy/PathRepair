import math
a,b,c=map(int,input().split())
if c%(math.gcd(a,b))==0:
  print('YES')
else:
  print('NO')