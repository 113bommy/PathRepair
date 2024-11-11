from functools import reduce
from operator import *
from math import *
from sys import *
from string import *
from collections import *
setrecursionlimit(10**7)
dX= [-1, 1, 0, 0,-1, 1,-1, 1]
dY= [ 0, 0,-1, 1, 1,-1,-1, 1]
RI=lambda: list(map(int,input().split()))
RS=lambda: input().rstrip().split()
#################################################
n=RI()[0]
m=RI()
m.sort()
tot=sum(m)
avg=tot//n
ans=0
i=0
while i<n and m[i]<=avg:
    ans+=avg-m[i]
    i+=1
ans+=max((tot%n - (n-i)),0)
print(ans)
