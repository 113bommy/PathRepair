"""
    Template written to be used by Python Programmers.
    Use at your own risk!!!!
    Owned by enraged(rating - 5 star at CodeChef and Specialist at Codeforces).
"""
import io, os
import sys
from functools import lru_cache
from heapq import merge, heapify, heappop, heappush
from math import ceil, floor, gcd, fabs, factorial, fmod, sqrt, inf
from collections import defaultdict as dd, deque, Counter as c
from itertools import combinations as comb, permutations as perm
from bisect import bisect_left as bl, bisect_right as br, bisect
# sys.setrecursionlimit(2*pow(10, 6))
# sys.stdin = open("input.txt", "r")
# sys.stdout = open("output.txt", "w")
mod = pow(10, 9) + 7
mod2 = 998244353
# input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
def data(): return sys.stdin.readline().strip()
def out(var): sys.stdout.write(str(var))
def outln(var): sys.stdout.write(str(var)+"\n")
def l(): return list(sp())
def sl(): return list(ssp())
def sp(): return map(int, data().split())
def ssp(): return map(str, data().split())
def l1d(n, val=0): return [val for i in range(n)]
def l2d(n, m, val=0): return [l1d(n, val) for j in range(m)]


n = int(data())
graph = dd(set)
for i in range(n-1):
    u, v = sp()
    graph[u].add(v)
    graph[v].add(u)
arr = l()
if arr[0] != 1:
    outln("No")
    exit()
d = deque()
d.append(1)
i = 1
while d and i < n:
    temp = d.popleft()
    while arr[i] in graph[temp]:
        d.append(arr[i])
        i += 1
        if i == n:
            break
if i == n:
    outln('Yes')
    exit()
outln('No')
