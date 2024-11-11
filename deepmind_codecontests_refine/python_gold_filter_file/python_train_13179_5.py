#! /usr/bin/env/ python
# -*- coding=utf8 -*-

import sys

n = 0
num = [[]*2]
def check(i, j):
    num = a[i][j]
    for x in range(0, n):
        if x == i:
            continue
        for y in range(0, n):
            if y == j:
                continue
            if a[x][j] + a[i][y] == num:
                return False
    return True

if __name__ == '__main__':
    n = int(input().strip())
    a = [[] * 50] *50
    mark = 0
    for i in range(n):
        a[i] = list(map(int, input().strip().split()))
    for i in range(n):
        for j in range(n):
            if a[i][j] == 1:
                continue
            if check(i,j):
                mark = 1
            if mark == 1:
                break
        if mark == 1 :
            break
    if mark == 1:
        print('No')
    else:
         print('Yes')
