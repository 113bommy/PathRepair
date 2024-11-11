#!/usr/bin/python3

n, m = tuple(map(int, input().split()))
a = [list(map(int, input().split())) for _ in range(n)]

simple = [0] * (10**5 + 4)
simple[1] = 1
for i in range(2, 10**5 + 4):
    if simple[i] == 0:
        j = 2
        while i * j < 10**5 + 4:
            simple[i * j] = 1
            j += 1
simple[-1] = len(simple) - 1
for i in range(10**5 + 2, 0, -1):
    if simple[i] == 1:
        simple[i] = simple[i + 1]
    else:
        simple[i] = i
row = [0] * n
col = [0] * m
for i in range(n):
    for j in range(m):
        row[i] += simple[a[i][j]] - a[i][j]
        col[j] += simple[a[i][j]] - a[i][j]
print(min(row + col))
