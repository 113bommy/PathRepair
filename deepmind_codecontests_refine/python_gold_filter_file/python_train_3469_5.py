import sys
from itertools import zip_longest
EPS = 0.00000001

def read_floats():
    return [float(i) for i in sys.stdin.readline().strip().split()]

def read_int():
    return int(sys.stdin.readline().strip())

def probs(c, m, p, v):
    #print(f"calculating p({c, m, p, v})")

    if c > m:
        return probs(m, c, p, v)
    # so c <= m
    if c < EPS:
        if v >= m:
            return [p, 1 - p]
        else:
            return [p] + [(1 - p) * a for a in probs(0, m - v, p + v, v)]

    if c < EPS:
        pc = []
    elif v > c:
        pc = probs(0, m + c / 2, p + c / 2, v)
    else:
        pc = probs(c - v, m + v / 2, p + v / 2, v)

    if m < EPS:
        pm = []
    elif v > m:
        pm = probs(c + m / 2, 0, p + m / 2, v)
    else:
        pm = probs(c + v / 2, m - v, p + v / 2, v)

    return [p] + [m * a + c * b for a, b in zip_longest(pm, pc, fillvalue=0)]



t = read_int()
for i in range(t):
    c, m, p, v = read_floats()
    pb = probs(c, m, p, v)
    print(sum(a * b for a, b in zip(range(1, 20), pb)))
