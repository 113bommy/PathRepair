import sys
input = lambda: sys.stdin.readline().rstrip('\r\n')

import math

inp_vars_int = lambda: map(int, input().split())
inp_list_int = lambda: list(map(int, input().split()))

t = int(input())

for _ in range(t):
    _ = int(input())
    a = inp_list_int()
    n = len(a)
    a_s = sorted(enumerate(a), key = lambda x: x[1])
    min_diff = math.inf
    i_d = None
    for i in range(1, n):
        diff = a_s[i][1] - a_s[i-1][1]
        if  0 < diff < min_diff:
            i_d = i
            min_diff = diff
    cs = 0
    
    if min_diff in (math.inf, 0):
        b = [1] * (n-1) + [1 - n]
    else:
        b = [None for _ in range(len(a))]
        d2, d1 = a_s[i_d][0], a_s[i_d - 1][0]
        for i, ai in enumerate(a):
            if i in(d1, d2):
                continue
            sig = (cs > 0) == (ai > 0)
            bi = (1 - 2 * sig) * min_diff
            b[i] = bi
            cs += bi * ai
        mult = cs // min_diff
        if mult != 0:
            b[d2], b[d1] = -mult, mult
        else:
            a2, a1 = a[d2], a[d1]
            b[d2], b[d1] = a1 * math.gcd(a2 , a1), -a2 * math.gcd(a2 , a1)
    print(*b)
    # print(sum(ai * bi for ai, bi in zip(a, b)))