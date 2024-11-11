import math
N=int(input())
a=math.ceil(N/1.08)
if math.floor(a*1.08) == N:
  print(a)
else:
  print(":(")