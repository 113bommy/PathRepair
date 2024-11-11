import math
from itertools import combinations

eps = 10 ** -7

def midpoint(a, b):
    return (a[0] + b[0]) / 2, (a[1] + b[1]) / 2

def distance(a, b):
    return ((a[0] - b[0]) ** 2 + (a[1] - b[1]) ** 2) ** 0.5

def within(c, r, a):
    return (a[0] - c[0]) ** 2 + (a[1] - c[1]) ** 2 <= r ** 2 + eps

def tcircle(t1, t2, t3):
    x1, y1 = t1
    x2, y2 = t2
    x3, y3 = t3
    d = 2 * ((y1 - y3) * (x1 - x2) - (y1 - y2) * (x1 - x3))
    if d == 0:
        return (0.0, 0.0), -1.0
    x = ((y1 - y3) * (y1 ** 2 - y2 ** 2 + x1 ** 2 - x2 ** 2) - (y1 - y2) * (y1 ** 2 - y3 ** 2 + x1 ** 2 - x3 ** 2)) / d
    y = ((x1 - x3) * (x1 ** 2 - x2 ** 2 + y1 ** 2 - y2 ** 2) - (x1 - x2) * (x1 ** 2 - x3 ** 2 + y1 ** 2 - y3 ** 2)) / -d
    r = math.sqrt((x - x1) ** 2 + (y - y1) ** 2)
    return (x, y), r

def main():
    N = int(input())
    L = [tuple(map(int, input().split())) for _ in range(N)]
    br = float('inf')
    for p, q in combinations(L, 2):
        c, r = midpoint(p, q), distance(p, q) / 2
        if all(within(c, r, i) for i in L):
            return r
        ac, ar = (0.0, 0.0), 0.0
        for i in L:
            if within(c, r, i):
                continue
            pc, pr = tcircle(p, q, i)
            if pr == -1:
                break
            if ar < pr:
                ac, ar = pc, pr
        else:
            if ar < br and all(within(ac, ar, i) for i in L):
                br = ar
    return br

print(main())
