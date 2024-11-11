# -*- coding: utf-8 -*-
import sys
buff_readline = sys.stdin.buffer.readline
readline = sys.stdin.readline


def read_int():
    return int(buff_readline())


def read_int_n():
    return list(map(int, buff_readline().split()))


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


class Doubling():
    def __init__(self, N, a0):
        self.N = N
        self.nt = [[None] * N for i in range(N.bit_length())]
        for i, a in enumerate(a0):
            self.nt[0][i] = a

        for i in range(1, len(self.nt)):
            for j in range(N):
                if self.nt[i-1][j] is None:
                    self.nt[i][j] = None
                else:
                    self.nt[i][j] = self.nt[i-1][self.nt[i-1][j]]

    def apply(self, i, n):
        j = i
        for k in range(n.bit_length()):
            m = 1 << k
            if m & n:
                j = self.nt[k][j]
            if j is None:
                break
        return j


def slv(N, X, L, Q, AB):
    r = [0]
    for x in X:
        t = -1
        for j in range(r[-1], len(X)):
            if X[j] - x <= L:
                t = j
            else:
                break
        r.append(t)
    r.pop(0)

    d = Doubling(N, r)

    ans = []
    for a, b in AB:
        if a > b:
            a, b = b, a
        a -= 1
        b -= 1
        bisect = Bisect(lambda x: d.apply(a, x))
        i = bisect.bisect_left(b, 0, len(X)+1)
        ans.append(i)

    return ans


def main():
    N = read_int()
    X = read_int_n()
    L = read_int()
    Q = read_int()
    AB = [read_int_n() for _ in range(Q)]
    print(*slv(N, X, L, Q, AB), sep='\n')


if __name__ == '__main__':
    main()
