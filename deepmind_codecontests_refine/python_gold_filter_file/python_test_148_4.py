
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
    w, h = map(int, input().split())
    ans = 0
    for i in range(4):
        a = list(map(int, input().split()))[1:]
        ans = max(ans, (a[-1] - a[0]) * (h if i < 2 else w))
    print(ans)


if __name__ == '__main__':
    for _ in range(int(input())):
        slv()
