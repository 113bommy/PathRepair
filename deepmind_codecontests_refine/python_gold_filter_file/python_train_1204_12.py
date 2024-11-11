import sys
input=sys.stdin.readline
from math import *
n=int(input())
a=[int(x) for x in input().split()]
d=[0 for i in range(10**5+9)]
for i in range(n):
    for j in range(1,int(sqrt(a[i]))+1):
        if a[i]%j==0:
            if a[i]//j==j:
                d[j]+=1
            else:
                d[j]+=1
                d[a[i]//j]+=1
            
print(max(1,max(d[2:])))                