###############################################################################

import sys
from sys import stdout
from bisect import bisect_left as binl
from copy import copy, deepcopy
from collections import defaultdict
import math


mod = 1


def intin():
    input_tuple = input().split()
    if len(input_tuple) <= 1:
        return int(input_tuple[0])
    return tuple(map(int, input_tuple))


def intina():
    return [int(i) for i in input().split()]


def intinl(count):
    return [intin() for _ in range(count)]


def modadd(x, y):
    global mod
    return (x + y) % mod


def modmlt(x, y):
    global mod
    return (x * y) % mod


def mod_inv(x):
    # available only when mod is prime
    global mod
    return pow(x, mod - 2, mod)


def gcm(x, y):
    while y != 0:
        z = x % y
        x = y
        y = z
    return x


def combination(x, y):
    assert(x >= y)

    ret = math.factorial(x)
    ret = ret // (math.factorial(x - y) * math.factorial(y))

    return ret


def get_divisors(x):
    retlist = []
    for i in range(1, int(x**0.5) + 3):
        if x % i == 0:
            retlist.append(i)
            retlist.append(x // i)
    return retlist


def get_factors(x):
    retlist = []
    for i in range(2, int(x**0.5) + 3):
        while x % i == 0:
            retlist.append(i)
            x = x // i
    retlist.append(x)
    return retlist


def make_linklist(xylist):
    linklist = {}
    for a, b in xylist:
        linklist.setdefault(a, [])
        linklist.setdefault(b, [])
        linklist[a].append(b)
        linklist[b].append(a)
    return linklist


def calc_longest_distance(linklist, v=1):
    distance_list = {}
    distance_count = 0
    distance = 0
    vlist_previous = []
    vlist = [v]
    nodecount = len(linklist)

    while distance_count < nodecount:
        vlist_next = []
        for v in vlist:
            distance_list[v] = distance
            distance_count += 1
            vlist_next.extend(linklist[v])
        distance += 1
        vlist_to_del = vlist_previous
        vlist_previous = vlist
        vlist = list(set(vlist_next) - set(vlist_to_del))

    max_distance = -1
    max_v = None
    for v, distance in distance_list.items():
        if distance > max_distance:
            max_distance = distance
            max_v = v

    return (max_distance, max_v)


def calc_tree_diameter(linklist, v=1):
    _, u = calc_longest_distance(linklist, v)
    distance, _ = calc_longest_distance(linklist, u)
    return distance


class UnionFind:

    def __init__(self, n):
        self.parent = [i for i in range(n)]

    def root(self, i):
        if self.parent[i] == i:
            return i
        self.parent[i] = self.root(self.parent[i])
        return self.parent[i]

    def unite(self, i, j):
        rooti = self.root(i)
        rootj = self.root(j)
        if rooti == rootj:
            return
        if rooti < rootj:
            self.parent[rootj] = rooti
        else:
            self.parent[rooti] = rootj

    def same(self, i, j):
        return self.root(i) == self.root(j)


###############################################################################


wvalue = []
cache = {}


def f(n, wvaluelen):
    global cache, wvalue
    if (n, wvaluelen) in cache:
        return cache[(n, wvaluelen)]
    if wvaluelen == 0:
        return 0
    if wvaluelen == 1:
        w, value = wvalue[0]
        ret = value * (n // w)
        cache[(n, wvaluelen)] = ret
        return ret

    ret = -1
    w, value = wvalue[wvaluelen-1]
    for i in range(n // w + 1):
        ret = max(ret, i * value + f(n - i * w, wvaluelen - 1))

    cache[(n, wvaluelen)] = ret
    return ret


def main():
    global cache, wvalue
    sys.setrecursionlimit(10000)

    n = intin()
    gsb_a = intina()
    gsb_b = intina()

    ga = gsb_a[0]
    sa = gsb_a[1]
    ba = gsb_a[2]

    gb = gsb_b[0]
    sb = gsb_b[1]
    bb = gsb_b[2]

    # a: buy
    if gb - ga > 0:
        wvalue.append((ga, gb - ga))
    if sb - sa > 0:
        wvalue.append((sa, sb - sa))
    if bb - ba > 0:
        wvalue.append((ba, bb - ba))

    value = f(n, len(wvalue))
    cache = {}
    wvalue = []

    # b: sell
    n += value

    # b: buy
    if ga - gb > 0:
        wvalue.append((gb, ga - gb))
    if sa - sb > 0:
        wvalue.append((sb, sa - sb))
    if ba - bb > 0:
        wvalue.append((bb, ba - bb))

    value = f(n, len(wvalue))
    cache = {}
    wvalue = []

    # a: sell
    n += value

    print(n)


if __name__ == '__main__':
    main()
