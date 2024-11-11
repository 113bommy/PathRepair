import math
r, x1, y1, x2, y2 = map(int, input().split())

d = 2 * r
dist = math.sqrt((x2-x1)**2 + (y2-y1)**2)

if dist % d == 0:
    print(int(dist / d))
else:
    print(int(dist / d) + 1)