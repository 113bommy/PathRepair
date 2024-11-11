import sys
#import random
from bisect import bisect_left as lb
from collections import deque
#sys.setrecursionlimit(10**8)
from queue import PriorityQueue as pq
from math import *
input_ = lambda: sys.stdin.readline().strip("\r\n")
ii = lambda : int(input_())
il = lambda : list(map(int, input_().split()))
ilf = lambda : list(map(float, input_().split()))
ip = lambda : input_()
fi = lambda : float(input_())
ap = lambda ab,bc,cd : ab[bc].append(cd)
li = lambda : list(input_())
pr = lambda x : print(x)
prinT = lambda x : print(x)
f = lambda : sys.stdout.flush()
inv =lambda x:pow(x,mod-2,mod)
mod = 10**9 + 7


n = ii()
a = ip().split()
ma = -float('inf')

#print(ord('Z'))

for i in a :
    t = 0

    for j in i :
        if (ord(j) >= 65 and ord(j) <91) :
            t += 1

    ma = max(ma,t)

print(ma)
