from functools import reduce
from math import gcd

N=int(input())
A=list(map(int, input().split()))
c=max(A)+1
C=[0]*c
f=1
for i in A:
    C[i]+=1

for i in range(2,c):
    cnt=0
    for j in range(i,c,i):
        cnt+=C[j]
    if cnt>1:
        f=0


if f==1:
    print('pairwise coprime')

elif reduce(gcd, A) == 1:
    print('setwise coprime')

else:
    print('not coprime')