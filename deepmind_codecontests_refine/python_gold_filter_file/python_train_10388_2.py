import sys
import math
import heapq
import bisect
sys.setrecursionlimit(10**7)
INTMAX = 9223372036854775807
INTMIN = -9223372036854775808
DVSR = 1000000007
def POW(x, y): return pow(x, y, DVSR)
def INV(x, m=DVSR): return pow(x, m - 2, m)
def DIV(x, y, m=DVSR): return (x * INV(y, m)) % m
def LI(): return map(int, sys.stdin.readline().split())
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def II(): return int(sys.stdin.readline())


def FLIST(n):
    res = [1]
    for i in range(1, n+1):
        res.append(res[i-1]*i % DVSR)
    return res


N = II()
AS = list(LI())

MP = {}

MX = 10**10
LIS = [10**10]*N
RES = [1]*N
for i in range(N-1):
    a, b = LI()
    a -= 1
    b -= 1
    if not a in MP:
        MP[a] = []
    if not b in MP:
        MP[b] = []
    MP[a].append(b)
    MP[b].append(a)


def dfs(v, mp, lis, p):
    for u in mp[v]:
        if u != p:
            i = bisect.bisect_left(lis, AS[u])
            bef = lis[i]
            lis[i] = AS[u]
            longest = bisect.bisect_left(lis, MX)
            RES[u] = longest
            dfs(u, mp, lis, v)
            lis[i] = bef


LIS[0] = AS[0]
dfs(0, MP, LIS, -1)

print(*RES, sep='\n')
