import math

n = int(input())
for i in range(n):
    xa, ya, ra, xb, yb, rb = map(float, input().split())
    d = math.sqrt((xb - xa) ** 2 + (yb - ya) ** 2)
    if d < ra - rb:
        print(2)
    elif d < rb - ra:
        print(-2)
    elif abs(rb - ra) <= d and d <= ra + rb:
        print(1)
    else:
        print(0)