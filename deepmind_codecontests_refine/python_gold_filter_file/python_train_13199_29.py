import math
N=int(input())
a=int(math.sqrt(N))
while a>0:
  if N%a==0:
    print(a+N//a-2)
    break
  a-=1
