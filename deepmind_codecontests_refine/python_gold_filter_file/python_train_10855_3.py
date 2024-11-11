from bisect import bisect_left as bl
from bisect import bisect_right as br
from heapq import heappush,heappop,heapify
import math
from collections import *
from functools import reduce,cmp_to_key
import sys
input = sys.stdin.readline

from itertools import accumulate
from functools import lru_cache

M = mod = 998244353
def factors(n):return sorted(set(reduce(list.__add__, ([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0))))
def inv_mod(n):return pow(n, mod - 2, mod)
 
def li():return [int(i) for i in input().rstrip('\n').split()]
def st():return input().rstrip('\n')
def val():return int(input().rstrip('\n'))
def li2():return [i for i in input().rstrip('\n')]
def li3():return [int(i) for i in input().rstrip('\n')]

 
for _ in range(val()):
    n = val()
    l = li()
    if n == 1:
        print(0)
        continue

    if sum(l) % n:
        print(-1)
        continue

    myaverage = sum(l) // n
    totoperations = 3 * n
    l1 = []
    for i in range(1, n):
        l1.append([1, i + 1, (-l[i]) % (i + 1)])
        l1.append([i + 1, 1, (l[i] + i) // (i + 1)])
        totoperations -= 2
    for i in range(1, n):
        totoperations -= 1
        l1.append([1, i + 1, myaverage])
    
    print(len(l1))
    for i in l1:print(*i)