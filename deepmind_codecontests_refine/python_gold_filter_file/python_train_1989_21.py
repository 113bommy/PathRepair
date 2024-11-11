
from math import *
n=int(input())
m=int(input())
a=[int(input()) for x in range(n)]
t=max(a)
print(max((sum(a)+n+m-1)//n,max(a)),t+m)
