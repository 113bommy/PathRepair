import math
x,y = map(int,input().split(' '))
n = int(input())
res = 2e9
for i in range(n):
  xi,yi,v = map(int,input().split(' '))
  res = min(res, math.hypot(x-xi,y-yi)/v)
print(round(res,9))