import math
n,x= map(int,input().split())
a = [int(_) for _ in input().split()]
ru = [0]*(n+1)
for i in range(1,n+1):
  ru[i] = ru[i-1]+a[i-1]
ans = float("inf")
for i in range(1,n+1):
  tmp = 0
  l = math.ceil(n/i)
  for j in range(1,l+1):
    if j == 1:
        m = -i*(j+1)-1
        if m < -n:
          m = -n-1
        tmp += (ru[n]-ru[m])*5
    else:
        m = -i*(j+1)-1
        if m < -n:
          m = -n-1
        if -i*j-1 < -n:
          break
        tmp += (ru[-i*j-1]-ru[m])*(2*j+3)
  tmp += x*i
  ans = min(ans,tmp)
print(ans+n*x)