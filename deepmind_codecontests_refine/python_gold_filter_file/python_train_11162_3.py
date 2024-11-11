from collections import defaultdict
from math import gcd

n = int(input())
points = []
for i in range(n):
    x, y = (int(i) for i in input().split(' '))
    points.append((x, y))
points.append(points[0])

if n % 2 == 1:
    print("NO")
else:
    d = defaultdict(lambda: 0)
    for i in range(len(points) - 1):
        x1, y1 = points[i]
        x2, y2 = points[i + 1]
        k1 = y2 - y1
        k2 = x2 - x1
        if (k2 <= 0 and k1 >= 0) or (k1 < 0 and k2 < 0):
            k1 = -k1
            k2 = -k2
        d[(k1, k2)] += 1

    flag = True
    for i in d:
        if d[i] % 2 != 0:
            flag = False
            break
    if flag:
        print("YES")
    else:
        print("NO")