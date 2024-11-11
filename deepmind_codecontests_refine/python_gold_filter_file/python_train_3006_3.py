import math
for _ in range(int(input())):
    x1, y1, x2, y2, x3, y3 = map(float, input().split())
    p = ((y1-y3)*(y1**2 -y2**2 +x1**2 -x2**2) -(y1-y2)*(y1**2 -y3**2 +x1**2 -x3**2)) / 2/ ((y1-y3)*(x1-x2)-(y1-y2)*(x1-x3))
    q = ((x1-x3)*(x1**2 -x2**2 +y1**2 -y2**2) -(x1-x2)*(x1**2 -x3**2 +y1**2 -y3**2)) / 2/ ((x1-x3)*(y1-y2)-(x1-x2)*(y1-y3))
    r = math.sqrt((x1 - p) ** 2 + (y1 - q) ** 2)
    print("{:.3f} {:.3f} {:.3f}".format(p, q, r))
