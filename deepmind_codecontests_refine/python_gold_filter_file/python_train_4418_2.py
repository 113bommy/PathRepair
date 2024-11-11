# Design_by_JOKER
import math
import cmath

n = int(input())
w = []
a = []
b = []
for _ in range(n):
    w.append(list(map(int, input().split())))
    a.append([0.0]*n)
    b.append([0.0]*n)

for x in range(n):
    a[x][x] = 1.0*w[x][x]
    for y in range(x):
        a[x][y] = a[y][x] = (w[x][y] + w[y][x])/2
        b[x][y] = w[x][y] - a[x][y]
        b[y][x] = -b[x][y]

for x in range(n):
    for y in range(n):
        print(a[x][y], end=' ')
    print("")

for x in range(n):
    for y in range(n):
        print(b[x][y], end=' ')
    print("")
