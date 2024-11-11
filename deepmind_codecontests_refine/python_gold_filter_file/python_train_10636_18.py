
# -*- coding: utf-8 -*-
# @Date    : 2019-07-18 08:20:21
# @Author  : raj lath (oorja.halt@gmail.com)
# @Link    : link
# @Version : 1.0.0

import sys
sys.setrecursionlimit(10**5+1)

inf     =  int(10 ** 20)
max_val =  inf
min_val = -inf

RW  = lambda : sys.stdin.readline().strip()
RI  = lambda : int(RW())
RMI = lambda : [int(x) for x in sys.stdin.readline().strip().split()]
RWI = lambda : [x for x in sys.stdin.readline().strip().split()]

MOD = 998244353
nb = RI()
na = [x for x in input().split()]
ans = 0
for x in na:
    current = ''
    for y in x:
        current += y * 2
    current = int(current)
    ans += current
    ans %= MOD
ans *= nb
ans %= MOD
print(ans)

