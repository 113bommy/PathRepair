from itertools import combinations
from functools import reduce
from operator import xor
l, r, k = map(int, input().split())

def bruteforce(l, r, k):
    rc = []
    rv = float('inf')
    for i in range(1, min(k, r - l + 1) + 1):
        for c in combinations(range(l, r + 1), i):
            v = reduce(xor, c)
            if v < rv:
               rc = c[:]
               rv = v
    return rv, rc
    
def large(l, r, k):
    if l % 2 != 0:
        l += 1
    return 0, list(range(l, l + 4))

def one(l, r, k):
    return l, [l]

def two(l, r, k):
    if l % 2 != 0:
        l += 1
    return 1, list(range(l, l + 2))

def three(l, r, k):
    #
    #   10000101010111 == r
    #
    # x 01000000000000
    # x 11000101010111 >= r
    #
    # o 00000111111111
    # o 10000010101000 < r
    #
    lgr = 0
    while (1 << lgr) <= r:
        lgr += 1
    lgr -= 1
    if lgr < 0:
        return two(l, r, k)
    t = r ^ (1 << lgr)
    lgr -= 1
    while lgr >= 0 and not (t & (1 << lgr)):
        lgr -= 1
    if lgr < 0:
        return two(l, r, k)
    lgr += 1
    if (1 << lgr) - 1 >= l:
        x1 = r
        x2 = (1 << lgr) - 1
        x3 = x1 ^ x2
        return 0, [x1, x2, x3]
    else:
        return two(l, r, k)

if r - l + 1 <= 4:
    rv, rc = bruteforce(l, r, k)
elif k >= 4:
    rv, rc = large(l, r, k)
elif k == 1:
    rv, rc = one(l, r, k)
elif k == 2:
    rv, rc = two(l, r, k)
elif k == 3:
    rv, rc = three(l, r, k)
else:
    assert False
print(rv)
print(len(rc))
print(*rc)
