from sys import stdin as cin
from fractions import Fraction as f
import math

n,v = map(int,cin.readline().split())
r=[]
for t in range(n):
    
    a=list(map(int,cin.readline().split()))

    for i in range(1,a[0]+1):
        if a[i]<v:
            r.append(t+1)
            break
print(len(r))
for x in r:
    print(x,end=' ')



