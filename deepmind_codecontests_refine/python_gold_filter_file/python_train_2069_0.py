from math import atan2

class Point(object):
    def __init__(self, x, y):
        self.x = x
        self.y = y

class Vector(object):
    def __init__(self, p1, p2):
        self.x = p2.x - p1.x
        self.y = p2.y - p1.y

    def cross(self, other: "Vector") -> float:
        return self.x*other.y - self.y*other.x

def grahams_scan(a: list):
    a.sort(key=lambda p: p.y)
    bottom_x, bottom_y = a[0].x, a[0].y
    _a = sorted(a[1:], key=lambda p: atan2(bottom_y-p.y, bottom_x-p.x)) + [a[0]]
    result = [a[0], _a[0]]

    for next_point in _a[1:]:
        while Vector(result[-1], result[-2]).cross(Vector(result[-1], next_point)) >= 0:
            result.pop()
        result.append(next_point)
    return result

while True:
    n = int(input())
    if not n:
        break
    a = [Point(*map(float, input().split(","))) for _ in [0]*n]
    result = grahams_scan(a)
    print(n-len(result)+1)
