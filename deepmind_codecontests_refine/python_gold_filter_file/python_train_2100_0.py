import bisect
import functools
import math
import sys
from collections import defaultdict

# input = sys.stdin.readline
rt = lambda: map(int, input().split())
ri = lambda: int(input())
rl = lambda: list(map(int, input().split()))


def main():
    s, b = rt()
    a = rl()
    bases = []
    for _ in range(b):
        bases.append(tuple(map(int, input().split())))

    bases.sort()
    defense = [x[0] for x in bases]
    pref = [0] * b
    for i in range(b):
        if i == 0:
            pref[i] = bases[i][1]
        else:
            pref[i] = pref[i-1] + bases[i][1]
    res = []
    for att in a:
        pos = bisect.bisect_right(defense, att)
        res.append(pref[pos-1] if pos > 0 else 0)

    print(*res)


if __name__ == '__main__':
    main()
