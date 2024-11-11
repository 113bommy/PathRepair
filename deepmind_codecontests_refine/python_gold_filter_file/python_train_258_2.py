import math


def Len (w):
    return w[0] * w[0] + w[1] * w[1]

n, x, y = input().split(' ')
n = int(n)
x = int(x)
y = int(y)

arr = []

for i in range(0, n):
    a, b = input().split(' ')
    a = int(a)
    b = int(b)
    arr.append([a, b])

r1 = 5000000000000
r2 = -500000000000

for i in range(0, n):
    st = [arr[(i + 1) % n][0] - arr[i][0], arr[(i + 1) % n][1] - arr[i][1]]
    r = [arr[i][0] - x, arr[i][1] - y]
    q = [arr[(i + 1) % n][0] - x, arr[(i + 1) % n][1] - y]
    d = q[0] * r[1] - q[1] * r[0]
    d *= d
    s = d/Len(st)
    if Len (q) - s < Len (st) and Len(r) - s < Len(st):
        r1 = min(r1, s)
        r2 = max(r2, s)

for i in arr:
    s = (x - i[0]) * (x - i[0]) + (y - i[1]) * (y - i[1])
    r1 = min(r1, s)
    r2 = max(r2, s)

print ((r2 - r1) * math.pi)