import sys
import math


def rl():
    return sys.stdin.readline().strip()


def rn():
    return list(map(int, sys.stdin.readline().strip().split()))


def rnn():
    return map(int, sys.stdin.readline().strip().split())


def rln(n):
    l = [None] * n
    for i in range(n):
        l[i] = int(rl())
    return l


if __name__ == '__main__':

    tc = int(input())
    for _ in range(tc):
        c, sum = rnn()
        q = sum // c
        r = sum % c
        res = 0
        if c < sum:
            res = (c - r) * q * q + r * (q + 1)* (q + 1)
        else:
            res = sum
        print(res)