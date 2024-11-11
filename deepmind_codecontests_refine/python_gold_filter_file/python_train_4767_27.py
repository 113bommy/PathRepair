#!/usr/bin/env python3

import sys

debug = False

def solve(ds, n, x, m):
    ds = [d % m for d in ds]

    nr_loop = (n - 1) // len(ds)
    lastloop_remaining = (n - 1) % len(ds)
    a_n = x
    cnt_zero = 0
    for i in range(0, len(ds)):
        dmod = ds[i] % m
        a_n += (dmod) * nr_loop
        if dmod == 0:
            cnt_zero += nr_loop
        if i < lastloop_remaining:
            a_n += dmod
            if dmod == 0:
                cnt_zero += 1
    cnt_decrease = a_n // m - x // m
    return n - 1 - cnt_decrease - cnt_zero


def read_int_list(sep = " "):
    return [int(s) for s in sys.stdin.readline().split(sep)]


def dprint(*args, **kwargs):
    if debug:
        print(*args, **kwargs)
    return


def main():
    k, q = read_int_list()
    d = read_int_list()
    for _ in range(0, q):
        n, x, m = read_int_list()
        print(str(solve(d, n, x, m)))
    

if __name__ == "__main__":
    main()