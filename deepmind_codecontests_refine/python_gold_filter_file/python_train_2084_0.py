from math import sqrt
xp0, yp0, xp1, yp1 = map(int, input().split())
a = [xp0, yp0]
b = [xp1, yp1]
q = int(input())

CCW = {1: 'COUNTER_CLOCKWISE',
       2: 'CLOCKWISE',
       3: 'ONLINE_BACK',
       4: 'ONLINE_FRONT',
       5: 'ON_SEGMENT',}

def dot(a, b):
    return sum([i * j for i,j in zip(a, b)])

def sub(a, b):
    return [a[0] - b[0],a[1] - b[1]]

def cross(a, b):
    return  a[0] * b[1] - a[1] * b[0]

def _abs(a):
    return sqrt(a[0] ** 2 + a[1] ** 2)

def ccw(a, b, c):
    x = sub(b, a)
    y = sub(c, a)
    if cross(x, y) > 0: return 1
    if cross(x, y) < 0: return 2
    if dot(x, y) < 0: return 3
    if _abs(x) < _abs(y): return 4
    return 5

for i in range(q):
    c = list(map(int, input().split()))
    print(CCW[ccw(a, b, c)])
    