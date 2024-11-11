#!/usr/bin/python3.6
import bisect
n = int(input())
x = [int(item) for item in input().split()]
l = int(input())
q = int(input())
ab = []
for i in range(q):
    a, b = [int(item) for item in input().split()]
    a -= 1; b -= 1
    if a > b:
        a, b = b, a
    ab.append((a, b))

dt = [[0] * n for _ in range(18)]
for i, item in enumerate(x):
    dt[0][i] = bisect.bisect_right(x, item + l) - 1

for i in range(1, 18):
    for j in range(n):
        dt[i][j] = dt[i-1][dt[i-1][j]]

for a, b in ab:
    days = 0
    if a == b:
        print(days)
        continue
    for i in range(17, -1, -1):
        if dt[i][a] < b:
            a = dt[i][a]
            days += 2**i
    print(days + 1)