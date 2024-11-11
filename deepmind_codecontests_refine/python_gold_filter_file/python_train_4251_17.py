def comb(n,k,p):
  from math import factorial
  if n<0 or k<0 or n<k:return 0
  if n==0 and k==0:return 1
  a=factorial(n)%p
  b=factorial(k)%p
  c=factorial(n-k)%p
  return (a*power_func(b,p-2,p)*power_func(c,p-2,p))%p
def power_func(a,b,p):
  if b==0:
    return 1
  if b%2==0:
    d=power_func(a,b//2,p)
    return (d*d)%p
  else:
    return (a*power_func(a,b-1,p))%p
n,m=map(int,input().split())
mod=10**9+7
d=[]
for i in range(2,int(m**0.5)+1):
  if m%i==0:
    cnt=0
    while m%i==0:
      m//=i
      cnt+=1
    d.append(cnt)
if m>1:
  d.append(1)
ans=1
for k in d:
  ans=(ans*comb(k+n-1,k,mod))%mod
print(ans)