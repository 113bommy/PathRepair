import re
from collections import Counter
from sys import stderr
from typing import Union, Generator, List, Tuple
import string

INF = 2e18 + 3
EPS = 1e-10


def main():
    points = (500, 1000, 1500, 2000, 2500)
    times = tuple(map(int, input().split()))
    ns_wrong = tuple(map(int, input().split()))
    hs, hu = map(int, input().split())

    res = hs * 100 - hu * 50
    for i in range(5):
        res += max(0.3 * points[i],
                   (250 - times[i]) * points[i] / 250 - 50 * ns_wrong[i])

    print(int(res))


if __name__ == '__main__':
    main()
