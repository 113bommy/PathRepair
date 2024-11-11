#!/usr/bin/env python3
import sys


def f(b: int, n: int) -> int:
    if n < b:
        return n
    return f(b, n // b) + n % b


def sqrt(n: int):
    lb = 0
    hb = n + 1
    while hb - lb > 1:
        m = (lb + hb) // 2
        if m * m <= n:
            lb = m
        else:
            hb = m
    return lb


def solve(n: int, s: int):
    if s == n:
        print(n + 1)
        return
    sn = sqrt(n)
    for b in range(2, sn + 1):
        if f(b, n) == s:
            print(b)
            return
    for p in reversed(range(1, sn + 1)):
        q = s - p
        if q < 0:
            continue
        b, r = divmod(n - q, p)
        if r != 0 or b <= p:
            continue
        if f(b, n) == s:
            print(b)
            return
    print(-1)


def main():
    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    n = int(next(tokens))  # type: int
    s = int(next(tokens))  # type: int
    solve(n, s)


if __name__ == '__main__':
    main()
