import math
import sys


def In():
    return map(int, sys.stdin.readline().split())


def luckyperm():
    n = int(input())
    if not n % 2:
        print(-1)
        return
    other = []
    l = []
    for i in range(n):
        l.append(i)
        other.append((i+i)%n)
    print(*l)
    print(*l)
    print(*other)
luckyperm()