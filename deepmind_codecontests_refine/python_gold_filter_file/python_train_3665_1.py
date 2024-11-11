class UnionFindVerSize():
    def __init__(self, N):
        self._parent = [n for n in range(0, N)]
        self._size = [1] * N
        self.group = N

    def find_root(self, x):
        if self._parent[x] == x: return x
        self._parent[x] = self.find_root(self._parent[x])
        stack = [x]
        while self._parent[stack[-1]]!=stack[-1]:
            stack.append(self._parent[stack[-1]])
        for v in stack:
            self._parent[v] = stack[-1]
        return self._parent[x]

    def unite(self, x, y):
        gx = self.find_root(x)
        gy = self.find_root(y)
        if gx == gy: return

        self.group -= 1

        if self._size[gx] < self._size[gy]:
            self._parent[gx] = gy
            self._size[gy] += self._size[gx]
        else:
            self._parent[gy] = gx
            self._size[gx] += self._size[gy]

    def get_size(self, x):
        return self._size[self.find_root(x)]

    def is_same_group(self, x, y):
        return self.find_root(x) == self.find_root(y)

import sys,random,bisect
from collections import deque,defaultdict
from heapq import heapify,heappop,heappush
from itertools import permutations
from math import log,gcd

input = lambda :sys.stdin.buffer.readline()
mi = lambda :map(int,input().split())
li = lambda :list(mi())

k = li()
a = [li() for i in range(3)]
n = sum(k)

f = [0 for i in range(n+2)]
g = [0 for i in range(n+2)]

for i in range(k[0]):
    f[a[0][i]] -= 2
    g[a[0][i]] -= 1
for i in range(k[2]):
    f[a[2][i]] -= 1
    g[a[2][i]] -= 2

for i in range(1,n+2):
    f[i] += f[i-1]
for i in range(n,0,-1):
    g[i] += g[i+1]
for i in range(1,n+2):
    f[i] += i
    g[i] -= i

for i in range(n,-1,-1):
    g[i] = min(g[i],g[i+1])

res = min(n-k[0],n-k[2])
for l in range(n+1):
    tmp = k[0] + k[2] + n + 1 + f[l] + g[l+1]
    res = min(res,tmp)

print(res)
