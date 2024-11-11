# aadiupadhyay
import os.path
from math import gcd, floor, ceil
from collections import *
import sys
mod = 1000000007
INF = float('inf')
def st(): return list(sys.stdin.readline().strip())
def li(): return list(map(int, sys.stdin.readline().split()))
def mp(): return map(int, sys.stdin.readline().split())
def inp(): return int(sys.stdin.readline())
def pr(n): return sys.stdout.write(str(n)+"\n")
def prl(n): return sys.stdout.write(str(n)+" ")


if os.path.exists('input.txt'):
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')


def BS(val):
    i, j = 0, len(prime)-1
    ans = -1
    while i <= j:
        mid = (i+j)//2
        if prime[mid] < val:
            i = mid+1
        else:
            ans = mid
            j = mid - 1
    return ans


maxN = 10**6
x = [0 for i in range(maxN+1)]
i = 2
while i*i <= maxN:
    if not x[i]:
        for j in range(i*i, maxN+1, i):
            x[j] = 1
    i += 1
prime = [i for i in range(2, maxN+1) if not x[i]]

n, m = mp()
ans = INF
d = defaultdict(int)
l = [li() for i in range(n)]
for i in range(n):
    now = 0
    for j in range(m):
        cur = BS(l[i][j])
        d[(i, j)] = prime[cur]-l[i][j]
        now += prime[cur] - l[i][j]
    ans = min(ans, now)

for i in range(m):
    now = 0
    for j in range(n):
        now += d[(j, i)]
    ans = min(ans, now)
pr(ans)
