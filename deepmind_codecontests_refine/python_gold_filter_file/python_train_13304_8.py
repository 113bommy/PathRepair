l,r=map(int,input().split())
if r-l>=2019:print(0)
else:
  MIN=10000
  for i in range(l,r):
    for j in range(i+1,r+1):
      p = i*j%2019
      if p<MIN:MIN=p
  print(MIN)