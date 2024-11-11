from math import *
from collections import *
from operator import itemgetter
import bisect
ii = lambda: int(input())
iia = lambda: list(map(int,input().split()))
isa = lambda: list(input().split())
I = lambda:list(map(int,input().split()))
chrIdx = lambda x: ord(x)-96
idxChr = lambda x: chr(96+x)

t = ii()

for _ in range(t):
    n = ii()
    a = iia()
    a.sort()
    b = []
    for i in range(n//2):
        b.append(a[i])
        b.append(a[-(i+1)])
    if(n%2):
        b.append(a[n//2])
    #print(a)
    b = list(reversed(b))
    print(*b)