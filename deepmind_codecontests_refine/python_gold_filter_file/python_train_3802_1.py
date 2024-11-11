import sys
#import random
from bisect import bisect_right as rb
from collections import deque
#sys.setrecursionlimit(10**8)
from queue import PriorityQueue
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
mod = 10**9 + 7

n = ii()
a = il()

d = {}
ans = []

l = 1

for i in range (n) :
    if (d.get(a[i])) :
        ans.append([l,i+1])
        l = i+2
        d.clear()
    else :
        d[a[i]] = True

if (ans == []) :
    print(-1)
    exit(0)

ans[-1] = [ans[-1][0],n]

print(len(ans))
for i in ans :
    print(*i)
