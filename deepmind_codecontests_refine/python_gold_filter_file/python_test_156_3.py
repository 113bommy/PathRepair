import sys, array, bisect, collections, heapq, itertools, math, functools
sys.setrecursionlimit(100000)

def _r(): return sys.stdin.buffer.readline()
def rs(): return _r().decode('ascii').strip()
def rn(): return int(_r())
def rnt(): return tuple(map(int, _r().split()))
def rnl(): return list(rnt())
def rna(): return array.array('q', rnt())
def pnl(l): print(' '.join(map(str, l)))

def solve(n, k, a):
    s = sum(a)
    if s <= k:
        return 0
    sol = s - k
    a.sort()
    s -= a[0]
    for i in range(n-1, 0, -1):
        s -= a[i]
        c = n - i
        x = (k - s) // (c + 1)
        sol = min(sol, max(a[0] - x, 0) + c)
    return sol

for _ in range(rn()):
    n, k = rnt()
    a = rnl()
    print(solve(n, k, a))