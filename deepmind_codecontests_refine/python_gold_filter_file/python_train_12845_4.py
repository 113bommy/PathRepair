#!/usr/bin/env python3
n, k = map(int,input().split())
if k < int(n * (n - 1) / 2):
    for i in range(n):
        print(0, i)
else:
    print('no solution')
