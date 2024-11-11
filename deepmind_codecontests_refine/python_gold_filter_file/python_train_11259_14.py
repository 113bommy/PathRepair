
from math import ceil
n, t = map(int,input().split())

v = []

for onibus in range(n):
  si, di = map(int,input().split())
  if si == t:
    v.append(si)
  elif si < t:
    x = ceil((t-si)/di)
    v.append(x*di + si)

  else:
    v.append(si)
    
print(v.index(min(v))+1)