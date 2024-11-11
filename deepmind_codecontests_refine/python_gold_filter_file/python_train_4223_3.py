import sys
#import random
from bisect import bisect_right as rb
from collections import deque
#sys.setrecursionlimit(10**8)
from queue import PriorityQueue
#from math import *
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


for _ in range (1) :

    d,k,a,b,t = il()

    if (d<=k) :
        print(d*a)
        continue
    if (t + k*a > k*b) :
        print(k*a + (d-k)*b)
        continue

    c = d//k
    s = k*a
    e = d%k

    ans = (c*s) + ((c-1)*t + min(t + e*a, e*b))

    print(ans)
