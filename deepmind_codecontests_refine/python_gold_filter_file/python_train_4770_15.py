import sys, re
from collections import deque, defaultdict, Counter
from math import ceil, sqrt, hypot, factorial, pi, sin, cos, radians
from itertools import accumulate, permutations, combinations, product, islice
from operator import itemgetter, mul
from copy import deepcopy
from string import ascii_lowercase, ascii_uppercase, digits
from bisect import bisect, bisect_left
from fractions import gcd
from heapq import heappush, heappop
from functools import reduce
def input(): return sys.stdin.readline().strip()
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
def ZIP(n): return zip(*(MAP() for _ in range(n)))
sys.setrecursionlimit(10 ** 9)
INF = float('inf')

N, M = MAP()
mod = M

tree = [[] for _ in range(N+1)]  # 1-indexed
for _ in range(N-1):
	a, b = MAP()
	tree[a].append(b)
	tree[b].append(a)

root = 1
parent = [0]*(N+1)
order = []
stack = [root]
while stack:
    x = stack.pop()
    order.append(x)
    for y in tree[x]:
        if y == parent[x]:
            continue
        parent[y] = x
        stack.append(y)

dp_d = [0]*(N+1)

for v in order[::-1]:
    x = 1
    for node in tree[v]:
        x = (x * (dp_d[node]+1))%mod
    dp_d[v] = x

dp_u = [1]*(N+1)
modmul = lambda x, y: x*y%mod
for v in order:
    p = parent[v]
    val = [dp_d[node]+1 if node != p else dp_u[v] for node in tree[v]]
    left = [1] + list(accumulate(val, modmul))[:-1] # 左累積和
    right = list(accumulate(val[::-1], modmul))[-2::-1] + [1] # 右累積和
    contrib = [x*y%mod for x, y in zip(left, right)]
    for node, c in zip(tree[v], contrib):
        if node != p:
            dp_u[node] = 1+c

ans = []
for xd, xu in zip(dp_d[1:], dp_u[1:]):
    ans.append(xd*xu%mod)
print(*ans, sep="\n")
