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

mx = 4*10**4

adj = [1 for i in range (mx)]

p = 2

adj[0] = 0
adj[1] = 0

while (p*p < mx) :
    if (adj[p] == 1) :
        for i in range(p*p,mx,p) :
            adj[i] = 0

    p += 1

prime = []

for i in range (mx) :
    if (adj[i] == 1) :
        prime.append(i)

#print(len(prime))

def cal (x) :
    t = 0

    for i in prime :
        while (x%i == 0) :
            t += 1
            x = x//i

        if (x == 1) :
            break

    if (x > 1) :
        t += 1

    return t
            

    
for _ in range (ii()) :
    a,b,k = il()

    t1 = cal(a)
    t2 = cal(b)

    if (a == b) :
        if (k == 1) :
            print("NO")
            continue
        if (k>=2 and k<= t1+t2) :
            print("YES")
        else :
            print("NO")

        continue
    if (a == 1 or b == 1) :
        if (k>=1 and k<= t1 + t2) :
            print("YES")
        else :
            print("NO")

        continue
    
    if (gcd(a,b) != 1) :
        if (gcd(a,b) == a or gcd(a,b) == b) :
            if (k >= 1 and k<= t1+t2) :
                print("YES")
            else :
                print("NO")
        else :
            if (k >= 2 and k<= t1+t2) :
                print("YES")
            else :
                print("NO")
    else :
        if (k >= 2 and k <= t1 + t2) :
            print("YES")
        else :
            print("NO")

    
    
