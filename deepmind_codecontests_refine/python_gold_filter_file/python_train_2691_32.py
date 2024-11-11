from math import ceil
n,a,b=map(int,input().split())
h=[int(input()) for i in range(n)]
def enough(x):
  cnt=0
  for i in range(n):
    if h[i]-x*b<=0:
      continue
    cnt+=ceil((h[i]-x*b)/(a-b))
  if cnt<=x:
    return True
  else:
    return False
l=0
r=10**9
while r-l>1:
  mid=(r+l)//2
  if enough(mid):
    r=mid
  else:
    l=mid
print(r)