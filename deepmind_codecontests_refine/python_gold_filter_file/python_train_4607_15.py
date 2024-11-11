# -*- coding: utf-8 -*-
import sys
# sys.setrecursionlimit(10**6)
buff_readline = sys.stdin.buffer.readline
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


@mt
def slv(A, B):
    return A + B


def main():
    T = read_int()
    for _ in range(T):
        A, B = read_int_n()
        print(slv(A, B))


if __name__ == '__main__':
    main()
