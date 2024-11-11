import sys
from array import array  # noqa: F401
from typing import List, Tuple, TypeVar, Generic, Sequence, Union  # noqa: F401


def input():
    return sys.stdin.buffer.readline().decode('utf-8')


def main():
    n, m = map(int, input().split())
    a = sorted(tuple(map(int, input().split())) for _ in range(n))
    dp = array('i', [10**9]) * (m + 1)
    dp[0] = 0

    for xi, si in a:
        dp[min(xi + si, m)] = min(dp[min(xi + si, m)], dp[max(0, xi - si - 1)])

        for i, delta in zip(range(xi - si - 2, xi - si - m - 1, -1), range(2, m + 1)):
            dp[min(xi + si + delta - 1, m)] = min(
                dp[min(xi + si + delta - 1, m)],
                dp[i if i >= 0 else 0] + delta - 1
            )

        for i in range(m - 1, 0, -1):
            if dp[i] > dp[i + 1]:
                dp[i] = dp[i + 1]

    print(dp[-1])


if __name__ == '__main__':
    main()
