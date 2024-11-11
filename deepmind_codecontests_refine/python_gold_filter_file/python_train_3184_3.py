import sys
from array import array  # noqa: F401
from typing import List, Tuple, TypeVar, Generic, Sequence, Union  # noqa: F401


def input():
    return sys.stdin.buffer.readline().decode('utf-8')


def main():
    from collections import deque
    ts, tf, t = map(int, input().split())
    n = int(input())
    a = list(map(int, input().split()))[::-1]
    point = sorted((set(a) | set(x - 1 for x in a) | {0, tf - t}) - {-1}) + [10**18]
    ans, wait = [-1], [10**18]
    dq = deque()

    def end():
        print(ans, wait, dq, file=sys.stderr)
        print(ans[0])
        exit()

    def refresh(time):
        if (time if not dq else dq[-1]) + t > tf:
            end()
        if not dq:
            if time < ts:
                if ts - time < wait[0]:
                    ans[0] = time
                    wait[0] = ts - time
            else:
                ans[0] = time
                end()
        else:
            if dq[-1] - time < wait[0]:
                ans[0] = time
                wait[0] = dq[-1] - time

    for i, p in enumerate(point[:-1]):
        while a and a[-1] == p:
            dq.append(max(dq[-1] if dq else p, ts) + t)
            a.pop()

        refresh(p)

        while dq and dq[0] < point[i + 1]:
            cur = dq.popleft()
            refresh(cur)

    end()


if __name__ == '__main__':
    main()
