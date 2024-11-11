import math
N = int(input())
for _ in [0]*N:
    x1, y1, r1, x2, y2, r2 = map(float, input().split())
    dist = math.hypot(x2-x1, y2-y1)
    if dist+r2 < r1:
        print(2)
    elif dist+r1 < r2:
        print(-2)
    elif dist <= r1+r2:
        print(1)
    else:
        print(0)
