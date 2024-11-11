import collections
import math
n,m=map(int,input().split())
flag=0
P=[]
p=m
while flag==0:
  cur=p
  for i in range(2,int(p**0.5)+1):
    if p%i==0:
      P.append(i)
      p//=i
      break
  if p==cur:
    P.append(p)
    flag=1
c=collections.Counter(P)
Primes=set(P)
def f(i):
  return math.factorial(i)
def fn(i):
  return f(n+i-1)//(f(n-1)*f(i))%(10**9+7)
ans=1
for p in Primes:
  ans*=fn(c[p])
  ans%=(10**9+7)
print(1 if m==1 else ans) 
