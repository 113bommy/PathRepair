from math import sqrt
q = int(input())

def norm(a):
    return sqrt(a[0] ** 2 + a[1] ** 2)

def dot(a, b):
    return sum([i * j for i,j in zip(a, b)])

def sub(a, b):
    return [a[0] - b[0],a[1] - b[1]]

def cross(a, b):
    return  a[0] * b[1] - a[1] * b[0]

def ccw(a, b, c):
    x = sub(b, a)
    y = sub(c, a)
    if cross(x, y) > 0: return 1
    if cross(x, y) < 0: return -1
    if dot(x, y) < 0: return 2
    if norm(x) < norm(y): return -2
    return 0

def intersect(p1, p2, p3, p4):
    return ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 and \
           ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0

for i in range(q):
    xp0, yp0, xp1, yp1, xp2, yp2, xp3, yp3 = map(int, input().split())
    print(1 if intersect([xp0, yp0], [xp1, yp1], [xp2, yp2], [xp3, yp3]) else 0)