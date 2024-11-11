from math import gcd
from functools import reduce
from collections import defaultdict
n=int(input())
a=list(map(int,input().split()))

if reduce(gcd,a)!=1:
  print("not coprime")
  exit()

def primes(x):
  ret=[]
  for i in range(1,int(x**0.5)+1):
    if x%i==0:
      ret.append(i)
      if x//i!=i:
        ret.append(x//i)
  ret.sort()
  return ret[1:]
      
s=set()
for q in a:
  p=primes(q)
  for j in p:
    if j in s:
      print("setwise coprime")
      exit()
    s.add(j)
print("pairwise coprime")
