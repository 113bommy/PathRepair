import math

class Vector():
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def inner_product(self, vec):
        return self.x*vec.x + self.y*vec.y

    def outer_product(self, vec):
        return self.x*vec.y - self.y*vec.x

    def norm(self):
        return math.sqrt(self.x**2 + self.y**2)

n = int(input())
points = []
for i in range(n):
    x, y = list(map(int, input().split(' ')))
    points.append(Vector(x, y))
points.append(points[0])

area = 0
for i in range(n):
    a, b = points[i], points[i+1]
    if (a.x == 0 and a.y == 0) or (b.x == 0 and b.y == 0): continue
    theta = math.atan2(a.outer_product(b), a.inner_product(b))
    if theta > 0:
        area += abs(a.outer_product(b))/2
    elif theta < 0:
        area -= abs(a.outer_product(b))/2
print(area)
