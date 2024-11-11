
import sys
import pprint
import logging
from logging import getLogger

def input(): return sys.stdin.readline().rstrip("\r\n")


logging.basicConfig(format="%(message)s", level=logging.WARNING,)
logger = getLogger(__name__)
logger.setLevel(logging.INFO)


def debug(msg, *args):
    logger.info(f'{msg}={pprint.pformat(args)}')

# 30 MINUTES ATLEAST !!!!


###################################################################################################################


def slv():
    n, a, b = map(int, input().split())

    if abs(a - b) > 1 or a + b + 2 > n:
        print(-1)
        return

    arr = []
    if a > b:
        for i in range(a):
            arr += [i + 1, n - i]

        for i in range(n - a, a, -1):
            arr.append(i)

    elif b > a:
        se = set()
        for i in range(b):
            arr += [n - i, i + 1]
            se.add(n - i)
            se.add(i + 1)

        for i in range(1, n + 1):
            if i in se:
                continue
            arr.append(i)
    else:
        se = set()
        for i in range(a):
            arr += [i + 1, n - i]
            se.add(i + 1)
            se.add(n - i)

        for i in range(1, n + 1):
            if i in se:
                continue
            arr.append(i)

    print(*arr)


if __name__ == '__main__':
    for _ in range(int(input())):
        slv()
