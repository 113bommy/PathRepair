import sys
from bisect import *

sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline

def main():
    md = 10 ** 9 + 7

    def get_group(k):
        g = pd[k]
        if g < 0:
            return k
        gg = get_group(g)
        pd[k] = gg
        return gg

    def merge(j, k):
        g1 = get_group(j)
        g2 = get_group(k)
        if g1 != g2:
            d1 = -pd[g1]
            d2 = -pd[g2]
            if d2 > d1:
                g1, g2 = g2, g1
            pd[g2] = g1
            if d1 == d2:
                pd[g1] -= 1

    n, m = map(int, input().split())
    x = int(input())
    ee = []
    for _ in range(m):
        u, v, w = map(int, input().split())
        ee.append((w, u - 1, v - 1))
    ee.sort()
    # print(ee)

    # union find 準備
    n_nodes = n - 1
    pd = [-1] * (n_nodes + 1)
    # 無条件の最小全域木を作る
    dd = [-1] * m
    s = 0
    for i in range(m):
        w, u, v = ee[i]
        if get_group(u) == get_group(v): continue
        s += w
        merge(u, v)
        dd[i] = 0
    # 最小サイズがxを超えていたら終わり
    if s > x:
        print(0)
        exit()
    # 使った辺に最小サイズを記録
    for i in range(m):
        if dd[i] == 0: dd[i] = s
    # 使っていない辺を1つずつ試して、サイズを記録
    for si in range(m):
        if dd[si] != -1: continue
        pd = [-1] * (n_nodes + 1)
        w, u, v = ee[si]
        dd[si] = 0
        merge(u, v)
        s = w
        for i in range(m):
            w, u, v = ee[i]
            if get_group(u) == get_group(v): continue
            s += w
            merge(u, v)
            if dd[i] == -1:
                dd[i] = 0
        for i in range(m):
            if dd[i] == 0: dd[i] = s
    dd.sort()

    # print(dd)
    # print(xi, x1i)
    def cnt(k):
        idx = bisect_right(dd, k)
        res = pow(2, m - idx + 1, md) - 2
        if idx == 0:
            res = pow(2, m, md) - 2
        return res

    print((cnt(x - 1) - cnt(x)) % md)

main()
