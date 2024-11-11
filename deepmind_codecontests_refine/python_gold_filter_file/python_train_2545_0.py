import math

x1, y1, x2, y2 = [int(x) for x in input().split()]
a, b = 0, 0
if x1 == x2:
    # adjacent tree - side parallel to y-axis
    side = abs(y2 - y1)
    if -1000 <= x1 + side <= 1000:
        a = x1 + side
        b = x1 + side
        print(a, y2, b, y1)
    else:
        if -1000 <= x1 - side <= 1000:
            a = x1 - side
            b = x1 - side
            print(a, y2, b, y1)
        else:
            print(-1)
elif y1 == y2:
    # adjacent tree - side parallel to x-axis
    side = abs(x2 - x1)
    if -1000 <= y1 + side <= 1000:
        a = y1 + side
        b = y1 + side
        print(x1, b, x2, a)
    else:
        if -1000 <= y1 - side <= 1000:
            a = y1 - side
            b = y1 - side
            print(x1, b, x2, a)
        else:
            print(-1)
else:
    # trees at diagonal
    if abs(y2 - y1) == abs(x2 - x1):
        side = abs(x2 - x1)
        if y1 > y2:
            print(x1, y1 - side, x2, y2 + side)
        else:
            print(x1, y1 + side, x2, y2 - side)
    else:
        print(-1)
