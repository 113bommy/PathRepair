from collections import Counter, OrderedDict
from itertools import permutations as perm
from collections import deque
from sys import stdin
from bisect import *
from heapq import *
import math

g   = lambda : stdin.readline().strip()
gl  = lambda : g().split()
gil = lambda : [int(var) for var in gl()]
gfl = lambda : [float(var) for var in gl()]
gcl = lambda : list(g())
gbs = lambda : [int(var) for var in g()]
mod = int(1e9)+7
inf = float("inf")

def ncr(n, r, p): 
    # initialize numerator 
    # and denominator 
    num = den = 1 
    for i in range(r): 
        num = (num * (n - i)) % p 
        den = (den * (i + 1)) % p 
    return (num * pow(den,  
            p - 2, p)) % p 


n, m = gil()

if n == 2:
	print(0)
else:
	p = [1]*(n)
	mod = 998244353
	for i in range(1, n):
		p[i] = (2*p[i-1])%mod
	print((p[n-3]*ncr(m, n-1, mod)*(n-2))%mod)
