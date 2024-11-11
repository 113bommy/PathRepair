import math
for _ in range(int(input())):
    xa, ya, ra, xb, yb, rb = map(float, input().split())
    d = math.sqrt((xb - xa) ** 2 + (yb - ya) ** 2)
    if ra + rb < d:
        print(0)
    elif d + ra < rb:
        print(-2)
    elif d + rb < ra:
        print(2)
    else:
        print(1)
