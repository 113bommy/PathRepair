import math
x = [0] * 3
y = [0] * 3
def direct(x1, y1, x2, y2, x3, y3):
    a = ((x1 - x2) ** 2 + (y1 - y2) ** 2)
    b = ((x3 - x2) ** 2 + (y3 - y2) ** 2)
    c = ((x3 - x1) ** 2 + (y3 - y1) ** 2)
    if a + b == c and (x1 != x2 or y1 != y2) and (x3 != x2 or y3 != y2) and (x1 != x3 or y1 != y3):
        return True
    else:
        return False
flag = False
flag2 = False
x[0], y[0], x[1], y[1], x[2], y[2] = [int(i) for i in input().split()]
def check():
    fl = False
    if direct(x[0], y[0], x[1], y[1], x[2], y[2]) or direct(x[1], y[1], x[0], y[0], x[2], y[2]) or direct(x[0], y[0], x[2], y[2], x[1], y[1]):
        fl = True
    return fl
if check():
    flag = True
else:
    for i in range(3):
        x[i] += 1
        if check(): flag2 = True
        x[i] -= 2
        if check(): flag2 = True
        x[i] += 1
        y[i] += 1
        if check(): flag2 = True
        y[i] -= 2
        if check(): flag2 = True
        y[i] += 1
if flag:
    print('RIGHT')
else:
    if flag2:
        print('ALMOST')
    else:
        print('NEITHER')
