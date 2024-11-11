class vector:
    def __init__(self, x, y):
        self.x = x
        self.y = y

x0 = 0
y0 = 0
l = list()
n, m = map(int, input().split())
for i in range(n):
    x = input()
    if len(l) < 3:
        for j in range(m):
            if x[j] == '*':
                v = vector(i, j)
                l.append(v)
if l[0].x != l[1].x:
    x0 = l[0].x
else:
    x0 = l[2].x
if l[0].y != l[1].y:
    if l[0].y == l[2].y:
        y0 = l[1].y
    else:
        y0 = l[0].y
else:
    y0 = l[2].y
print(x0 + 1, end=" ")
print(y0 + 1, end=" ")
