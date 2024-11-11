from functools import reduce


def cross(a, b):
    return a.real * b.imag - a.imag * b.real


def graham_scan(points):
    points.sort(key=lambda p: (p.imag, p.real))
    lh = reduce(keep_left, points, [])
    uh = reduce(keep_left, reversed(points), [])
    lh.extend(uh[1:-1])
    return lh


def keep_left(hull, r):
    if hull:
        prev = hull.pop()
        while hull:
            p = hull[-1]
            if cross(prev - p, r - p) >= 0:
                hull.append(prev)
                break
            prev = hull.pop()
        else:
            hull.append(prev)
    if not hull or hull[-1] != r:
        hull.append(r)
    return hull


n = int(input())
points = [complex(*map(int, input().split())) for _ in range(n)]
result = graham_scan(points)
print(len(result))
for p in result:
    print(int(p.real), int(p.imag))