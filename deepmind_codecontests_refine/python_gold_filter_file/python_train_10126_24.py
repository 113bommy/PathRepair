import sys
import math
from functools import reduce
import bisect


def getN():
    return int(input())


def getNM():
    return map(int, input().split())


def getList():
    return list(map(int, input().split()))


def input():
    return sys.stdin.readline().rstrip()


def index(a, x):
    i = bisect.bisect_left(a, x)
    if i != len(a) and a[i] == x:
        return i
    return False


#############
# MAIN CODE #
#############

for _ in range(int(input())):
    n = getN()
    s = ''
    for _ in range(n):
        s += input()
    for i in s:
        if s.count(i) % n != 0:
            print("NO")
            break
    else:
        print("YES")
