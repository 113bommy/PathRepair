def arr_inp(n):
    if n == 1:
        return [int(x) for x in stdin.readline().split()]
    elif n == 2:
        return [float(x) for x in stdin.readline().split()]
    else:
        return [str(x) for x in stdin.readline().split()]


def cum_m():
    for l, r in k_a:
        m_cum[l] += 1
        m_cum[r + 1] -= 1
    for i in range(2, m + 1):
        m_cum[i] += m_cum[i - 1]


def cum_a():
    i = 1
    for l, r, d in m_a:
        a_cum[l] += (d * m_cum[i])
        a_cum[r + 1] -= (d * m_cum[i])
        i += 1
    for i in range(2, n + 1):
        a_cum[i] += a_cum[i - 1]


def solve():
    cum_m()
    cum_a()
    ans = [0] * n
    for i in range(n):
        ans[i] += a[i] + a_cum[i + 1]
    return ans


from sys import stdin
from collections import *

n, m, k = arr_inp(1)
a, m_cum, a_cum = arr_inp(1), defaultdict(int), defaultdict(int)
m_a, k_a = [arr_inp(1) for i in range(m)], [arr_inp(1) for j in range(k)]

print(*solve())

