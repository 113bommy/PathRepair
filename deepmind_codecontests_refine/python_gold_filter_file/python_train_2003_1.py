import math
t = int(input())
for i in range(t):
  n= int(input())
  ar = [int(i) for i in input().split()]
  st = ar[0]
  sec = []
  diff=0
  quw = False
  for l in range(n-1):
    if ar[l+1]>=st:
      st=ar[l+1]
    else:
      diff=int(math.log((st-ar[l+1]),2))
      if ar[l+1]+2**diff-1>st:
        sec.append(diff)
      else:
        sec.append(diff+1)
      quw = True
  if quw==False:
    print(0)
  else:
    print(max(sec))
