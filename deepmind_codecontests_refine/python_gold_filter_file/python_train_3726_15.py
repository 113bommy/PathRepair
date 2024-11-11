from decimal import Decimal
import sys
input = sys.stdin.readline


def dist(x1, x2, y1, y2):
    return (y1-y2)*(y1-y2)+(x1-x2)*(x1-x2)


def farthest(x, y):
    ret = 0
    point = (-1, -1)
    for u, v in X:
        d = dist(x, u, y, v)
        if d > ret:
            ret = d
            point = u, v
    return ret, point


N = int(input())
X = []
for _ in [0]*N:
    x, y = map(int, input().split())
    X.append((x, y))

x = (max(x for x, y in X) - min(x for x, y in X))/2
y = (max(y for x, y in X) - min(y for x, y in X))/2
x = Decimal(str(x))
y = Decimal(str(y))
step = Decimal('0.5')
o = 1
eps = Decimal('0.00000000000001')
while o > eps:
    _, (u, v) = farthest(x, y)
    x += (u-x)*step
    y += (v-y)*step
    step *= Decimal('0.999')
    o = (abs(u-x)+abs(x-y))*step

ans, _ = farthest(x, y)
ans **= Decimal('0.5')
print(ans)