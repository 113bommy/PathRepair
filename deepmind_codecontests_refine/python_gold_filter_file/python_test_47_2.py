# cook your dish here
import sys
#import random
from bisect import bisect_left as lb
from bisect import bisect_right as rb
from collections import deque
#sys.setrecursionlimit(10**8)
from queue import PriorityQueue as pq
from math import gcd
#import math
input_ = lambda: sys.stdin.readline().strip("\r\n")
ii = lambda : int(input_())
il = lambda : list(map(int, input_().split()))
ilf = lambda : list(map(float, input_().split()))
lii = lambda : list(map(int, list(ip())))
ip = lambda : input_()
fi = lambda : float(input_())
ap = lambda ab,bc,cd : ab[bc].append(cd)
li = lambda : list(input_())
pr = lambda x : print(x)
prinT = lambda x : print(x)
f = lambda : sys.stdout.flush()
inv =lambda x:pow(x,mod-2,mod)
dx = [0,0,1,-1]
dy = [1,-1,0,0]
mod = 10**9 + 7
mod1 = 998244353

for _ in range (ii()) :
    n,k = il()
    a = il()

    a.sort()

    j = -1

    c = []
    
    for i in range (n) :
        if (a[i] > 0) :
            break
        if (i <= j) :
            continue
        for mn in range (k) :
            if (i + mn >= n) :
                break
            if (a[i] < 0 and a[i+mn] > 0) :
                break
            j = i + mn

        c.append(2*abs(a[i]))
    #print(c)
    j = n
    for i in range (n-1,-1,-1) :
        if (a[i] < 0) :
            break
        if (i >= j) :
            continue
        for mn in range (k) :
            if(i - mn < 0) :
                break
            if (a[i] > 0 and a[i-mn] < 0) :
                break
            j = i - mn

        c.append(2*abs(a[i]))

    c.sort()

    #print(c)

    s = sum(c)
    s -= c[-1]//2

    print(s)
