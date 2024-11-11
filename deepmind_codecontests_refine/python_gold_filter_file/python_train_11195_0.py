import sys
import math

def top2(sx, sy, tx, ty, n, px, py):
    t1 = -1e18
    p1 = -1
    t2 = -1e18
    p2 = -1
    for i in range(n):
        v = math.sqrt((px[i] - tx) ** 2 + (py[i] - ty) ** 2) - math.sqrt((px[i] - sx) ** 2 + (py[i] - sy) ** 2)
        if v > t1:
            t2 = t1
            p2 = p1
            t1 = v
            p1 = i
        elif v > t2:
            t2 = v
            p2 = i
    return [t1, p1, t2, p2]

if __name__ == "__main__":
    ax, ay, bx, by, tx, ty = [int(i) for i in sys.stdin.readline().strip().split()]
    n = int(sys.stdin.readline())
    px = [0] * n
    py = [0] * n
    for i in range(n):
        px[i], py[i] = [int(i) for i in sys.stdin.readline().strip().split()]
    sum = 0
    for i in range(n):
        sum += 2 * math.sqrt((px[i] - tx) ** 2 + (py[i] - ty) ** 2)
    at1, ap1, at2, ap2 = top2(ax, ay, tx, ty, n, px, py)
    bt1, bp1, bt2, bp2 = top2(bx, by, tx, ty, n, px, py)
    res = sum - max(at1, bt1)
    if ap1 == bp1:
        if ap2 != -1:
            res = min(res, sum - at1 - bt2)
            res = min(res, sum - bt1 - at2)
    else:
        res = min(res, sum - at1 - bt1)
    print(res)
