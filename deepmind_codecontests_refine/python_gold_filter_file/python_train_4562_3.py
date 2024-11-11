# -*- coding: utf-8 -*-

import sys
# sys.setrecursionlimit(10**6)
# buff_readline = sys.stdin.buffer.readline
buff_readline = sys.stdin.readline
readline = sys.stdin.readline

INF = 2**62-1


def read_int():
    return int(buff_readline())


def read_int_n():
    return list(map(int, buff_readline().split()))


def read_float():
    return float(buff_readline())


def read_float_n():
    return list(map(float, buff_readline().split()))


def read_str():
    return readline().strip()


def read_str_n():
    return readline().strip().split()


def error_print(*args):
    print(*args, file=sys.stderr)


def mt(f):
    import time

    def wrap(*args, **kwargs):
        s = time.time()
        ret = f(*args, **kwargs)
        e = time.time()

        error_print(e - s, 'sec')
        return ret

    return wrap


class Bisect:
    def __init__(self, func):
        self.__func = func

    def bisect_left(self, x, lo, hi):
        while lo < hi:
            mid = (lo+hi)//2
            if self.__func(mid) < x:
                lo = mid+1
            else:
                hi = mid
        return lo

    def bisect_right(self, x, lo, hi):
        while lo < hi:
            mid = (lo+hi)//2
            if x < self.__func(mid):
                hi = mid
            else:
                lo = mid+1
        return lo


# @mt
def slv(N, Q, A, X):

    from itertools import accumulate
    sa = [0] + list(accumulate(A))
    sea = [0] + list(accumulate(a if i % 2 == 0 else 0 for i, a in enumerate(A)))
    soa = [0] + list(accumulate(a if i % 2 == 1 else 0 for i, a in enumerate(A)))

    for x in X:
        def f(n):
            if 2*n-1 > N:
                return 1
            t = abs(x-A[-n])
            a = max(abs(x-A[-n-1]), abs(x-A[-2*n+1]))
            if a <= t:
                return 0
            return 1
        n = Bisect(f).bisect_left(1, 1, N) - 1
        ans = sa[N] - sa[N-n]
        r  = max(0, N - 2*n)
        if r % 2 == 0:
            ans += soa[r] - soa[0]
        else:
            ans += sea[r] - sea[0]
        print(ans)

def main():
    N, Q = read_int_n()
    A = read_int_n()
    X = [read_int() for _ in range(Q)]
    slv(N, Q, A, X)

if __name__ == '__main__':
    main()
