import sys
from array import array  # noqa: F401
import typing as Tp  # noqa: F401


def input():
    return sys.stdin.buffer.readline().decode('utf-8')


def read_int():
    res = b''

    while True:
        d = sys.stdin.buffer.read(1)
        if d == b'-' or d.isdigit():
            res += d
        elif res:
            break

    return int(res)


def main():
    from gc import collect

    n, m = (read_int(), read_int())
    acc = array('i', [0]) * (n + 1)
    for _ in range(n):
        acc[read_int()] += 1
    for i in range(n):
        acc[i + 1] += acc[i]

    collect()

    query = array('i', [0]) * m
    for i in range(m):
        query[i] = read_int()

    collect()

    ok, ng = n + 1, 0
    while abs(ok - ng) > 1:
        mid = (ok + ng) >> 1
        cnt = acc[mid]

        for q in query:
            if q > 0:
                if mid >= q:
                    cnt += 1
            else:
                if cnt >= -q:
                    cnt -= 1

        if cnt:
            ok = mid
        else:
            ng = mid

    print(ok if ok < n + 1 else 0)


if __name__ == '__main__':
    main()
