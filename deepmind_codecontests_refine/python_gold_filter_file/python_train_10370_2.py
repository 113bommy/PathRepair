def main():
    total = 0
    n, k = liee()
    a = array()
    cnt = 0
    for i in range(n):
        total += a[i]
        temp = min(8, total)
        cnt += temp
        total -= temp
        if cnt >= k:
            print(i + 1)
            exit()
    print(-1)

from sys import *
import inspect
import re
from math import *
import threading
from collections import *
from pprint import pprint as pp
mod = 998244353
MAX = 10**5


def lie():
    return int(input())


def liee():
    return map(int, input().split())


def array():
    return list(map(int, input().split()))


def deb(p):
    for line in inspect.getframeinfo(inspect.currentframe().f_back)[3]:
        m = re.search(r'\bdeb\s*\(\s*([A-Za-z_][A-Za-z0-9_]*)\s*\)', line)
        print('%s %s' % (m.group(1), str(p)))


def vec(size, val=0):
    vec = [val for i in range(size)]
    return vec


def mat(rowNum, colNum, val=0):
    mat = []
    for i in range(rowNum):
        collumn = [val for j in range(colNum)]
        mat.append(collumn)
    return mat


def dmain():
    setrecursionlimit(100000000)
    threading.stack_size(40960000)
    thread = threading.Thread(target=main)
    thread.start()


if __name__ == '__main__':
    # main()
    dmain()
