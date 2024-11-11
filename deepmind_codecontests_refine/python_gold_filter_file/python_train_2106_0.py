# -*- coding: utf-8 -*-

import sys

def input(): return sys.stdin.readline().strip()
def list2d(a, b, c): return [[c] * b for i in range(a)]
def list3d(a, b, c, d): return [[[d] * c for j in range(b)] for i in range(a)]
def list4d(a, b, c, d, e): return [[[[e] * d for j in range(c)] for j in range(b)] for i in range(a)]
def ceil(x, y=1): return int(-(-x // y))
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(N=None): return list(MAP()) if N is None else [INT() for i in range(N)]
def Yes(): print('Yes')
def No(): print('No')
def YES(): print('YES')
def NO(): print('NO')
# sys.setrecursionlimit(10 ** 9)
INF = 10 ** 18
MOD = 10 ** 9 + 7

def compress(S):
    zipped, unzipped = {}, {}
    for i, a in enumerate(sorted(S)):
        zipped[a] = i
        unzipped[i] = a
    return zipped, unzipped

for _ in range(INT()):
    N, M = MAP()

    TLR = []
    S = set()
    S.add(0)
    for i in range(N):
        t, l, r = MAP()
        S.add(t)
        TLR.append((t, l, r))
    zipped, unzipped = compress(S)
    L = len(zipped)
    TLR2 = [[] for i in range(L)]
    for i in range(N):
        t, l, r = TLR[i]
        t = zipped[t]
        TLR2[t].append((l, r))
    
    TLR2[0] = (0, 0)
    for i, li in enumerate(TLR2[1:], 1):
        mnl = -INF
        mxr = INF
        for l, r in li:
            mnl = max(mnl, l)
            mxr = min(mxr, r)
        TLR2[i] = (mnl, mxr)
    
    mnm = mxm = M
    for i, (l, r) in enumerate(TLR2[1:], 1):
        move = unzipped[i] - unzipped[i-1]
        if mnm <= l:
            if mxm + move < l:
                NO()
                break
            else:
                mnm = l
        else:
            if mnm - move > r:
                NO()
                break
            elif mnm - move > l:
                mnm -= move
            else:
                mnm = l
        if mxm >= r:
            if mnm - move > r:
                NO()
                break
            else:
                mxm = r
        else:
            if mxm + move < l:
                NO()
                break
            elif mxm + move < r:
                mxm += move
            else:
                mxm = r
        if mxm < mnm:
            NO()
            break
    else:
        YES()
