from collections import defaultdict
from math import gcd
import sys
input = sys.stdin.readline
N=int(input())
mod=10**9+7
dic=defaultdict(lambda: [0,0])
c=0
d=0
e=0
for i in [0]*N:
 A,B = map(int,input().split())
 if A==0 and B==0:
  e+=1
 elif A==0:
  c+=1
 elif B==0:
  d+=1
 else:
  g=gcd(A,B)
  A//=g
  B//=g
  if A*B>0:
   dic[(abs(A),abs(B))][0]+=1
  else:
   dic[(abs(B),abs(A))][1]+=1
ans=1
for k in dic:
 ans=ans*(pow(2,dic[k][0],mod)+pow(2,dic[k][1],mod) -1)
ans=ans*(pow(2,c,mod)+pow(2,d,mod)-1)
print((ans-1+e)%mod)