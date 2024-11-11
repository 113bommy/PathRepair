import math
import sys
x1, y1, x2, y2, x3, y3 = map(int, input().split())
x_1, y_1, x_2, y_2, x_3, y_3 = x1, y1, x2, y2, x3, y3
a = (x1 - x2) ** 2 + (y1 - y2) ** 2
b = (x1 - x3) ** 2 + (y1 - y3) ** 2
c = (x2 - x3) ** 2 + (y2 - y3) ** 2
if a == b + c or b == a + c or c == a + b:
    print('RIGHT')
    sys.exit()
x = [0, 0, 1, -1]
y = [1, -1, 0, 0]
for i in range(4):
    x1 += x[i]
    y1 += y[i]
    a = (x1 - x2) ** 2 + (y1 - y2) ** 2
    b = (x1 - x3) ** 2 + (y1 - y3) ** 2
    c = (x2 - x3) ** 2 + (y2 - y3) ** 2
    if (a == b + c or b == a + c or c == a + b) and (x3 - x1) * (y2 - y1) != (x2 - x1) * (y3 - y1):
        print('ALMOST')
        sys.exit()
    x1 = x_1
    y1 = y_1
for i in range(4):
    x2 += x[i]
    y2 += y[i]
    a = (x1 - x2) ** 2 + (y1 - y2) ** 2
    b = (x1 - x3) ** 2 + (y1 - y3) ** 2
    c = (x2 - x3) ** 2 + (y2 - y3) ** 2
    if (a == b + c or b == a + c or c == a + b) and (x3 - x1) * (y2 - y1) != (x2 - x1) * (y3 - y1):
        print('ALMOST')
        sys.exit()
    x2 = x_2
    y2 = y_2
for i in range(4):
    x3 += x[i]
    y3 += y[i]
    a = (x1 - x2) ** 2 + (y1 - y2) ** 2
    b = (x1 - x3) ** 2 + (y1 - y3) ** 2
    c = (x2 - x3) ** 2 + (y2 - y3) ** 2
    if (a == b + c or b == a + c or c == a + b) and (x3 - x1) * (y2 - y1) != (x2 - x1) * (y3 - y1):
        print('ALMOST')
        sys.exit()
    x3 = x_3
    y3 = y_3
print('NEITHER')
    

    

# Wed Oct 14 2020 18:56:44 GMT+0300 (Москва, стандартное время)
