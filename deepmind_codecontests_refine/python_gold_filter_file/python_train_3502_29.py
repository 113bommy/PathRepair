import sys
li  =   lambda : [int(x) for x in sys.stdin.readline().strip().split()]
rw  =   lambda : sys.stdin.readline().strip().split()
ni  =   lambda : int(sys.stdin.readline().strip())
nsi =   lambda : sys.stdin.readline().strip()

from collections import defaultdict as df
from math import *

n,m=map(int,input().split())

d={}

for i in range(n):
    name,ip=input().split()
    d[ip]=name

for i in range(m):
    a,b=input().split()
    b=b[:-1]
    print(a," "+b+'; #'+d[b])
