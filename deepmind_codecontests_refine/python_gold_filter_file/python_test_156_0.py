from sys import stdin, stdout, setrecursionlimit
from math import gcd, sqrt, factorial, pi, inf
from collections import deque, defaultdict
from bisect import bisect, bisect_left
from time import time
from itertools import permutations as per
from heapq import heapify, heappush, heappop, heappushpop

input = stdin.readline
R = lambda: map(int, input().split())
I = lambda: int(input())
S = lambda: input().rstrip('\r\n')
L = lambda: list(R())
P = lambda x: stdout.write(str(x) + '\n')
lcm = lambda x, y: (x * y) // gcd(x, y)
nCr = lambda x, y: (f[x] * inv((f[y] * f[x - y]) % N)) % N
inv = lambda x: pow(x, N - 2, N)
sumx = lambda x: (x ** 2 + x) // 2
N = 10 ** 9 + 7

def pro(s):
    return (k-s+a[0])//(i+1)

for _ in range(I()):
    n,k=R()
    a=L()
    a.sort()
    s=sum(a)
    if s<=k:
        print(0)
        continue
    p=s-k
    #print(a,s)
    for i in range(n):
        #print(a[-1],(s-k+n-i-1)//(n-i),s,k)
        p=min(p,i+max(0,a[0]-pro(s)))
        #print(pro(s),k-s)
        s-=a[-i-1]
        #print(i,p)
    print(p)
