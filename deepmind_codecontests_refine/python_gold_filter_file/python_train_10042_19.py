from math import *
k=int(input())
kk=sqrt(1+8*k)
a1=(-1+kk)/2
a2=(-1-kk)/2
b1=int(a1)
b2=int(a2)
if (a1==b1 or a2==b2) and (a1>0 or a2>0):
    print('YES')
else:
    print('NO')
