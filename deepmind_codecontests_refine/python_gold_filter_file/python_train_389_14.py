from math import gcd
from functools import reduce
n=int(input())
a=list(map(int,input().split()))
d=[0]*(10**6)
for i in a:
  d[i-1]+=1
num=2
while num<=10**6:
  if sum([d[i*num-1] for i in range(1,10**6//num+1)])>1:
      break
  num+=1
else:
  print('pairwise coprime')
  exit()
g=reduce(gcd,a)
if g==1:
  print('setwise coprime')
  exit()

print('not coprime')