from math import gcd
from itertools import product
w = int(input())
c = list(map(int,input().split()))
sm = sum([c[i]*(i+1) for i in range(8)])
per = 1
if sm < w:
  print(sm)
  exit()
elif sm < w+64:
  ans = 0
  ls = [list(range(0,min(c[i]+1,8))) for i in range(8)]
  for x in product(*ls):
    tmp = 0
    for i in range(8):
      tmp += (i+1)*x[i]
    if sm-tmp <= w:
      ans = max(ans,sm-tmp)
  print(ans)
  exit()
else:
  for i in range(8):
    for j in range(min(c[i],2520//(i+1))):
      per |= per<<(i+1)
      per &= (1<<2521)-1
rem = w%2520
ans = w
while per&1<<rem == 0:
  ans -= 1
  rem -= 1
print(ans)