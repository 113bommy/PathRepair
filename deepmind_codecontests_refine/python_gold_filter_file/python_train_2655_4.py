#!/usr/bin/env python3.4

import time

COL, ROW, LEN = 1000, 1000, 26
matrix = [[0] * COL for i in range(ROW)]
arr = [0] * LEN

direction = ((0, -1), (-1, 0), (0, 1), (1, 0))


class Pair:
    def __init__(self, x, y):
        self.x = x
        self.y = y


def timer(func, *pargs, **kargs):
    start = time.time()
    func(*pargs, **kargs)
    return time.time() - start


def test(a):
    answer = 0
    for value in a:
        if value >= 0:
            answer += value
    return answer


if __name__ == "__main__":
    n = int(input())
    arr = list(map(int, input().split()))
    ans = -1
    volume = 0
    direct = 0
    if test(arr) == 0:
        ans += 1
    while test(arr):
        ans += 1
        if direct == 0:
            for ind, val in enumerate(arr):
                if val <= volume and val != -1:
                    arr[ind] = -1
                    volume += 1
        else:
            for ind in range(len(arr) - 1, -1, -1):
                if arr[ind] <= volume and arr[ind] != -1:
                    arr[ind] = -1
                    volume += 1
        direct += 1
        direct %= 2
    print(ans)
