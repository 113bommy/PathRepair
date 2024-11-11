from math import *

n, h = (int(x) for x in input().split(' '))

if (h + 1) * h // 2 >= n:
    a = int(ceil((-1 + sqrt(1 + 8 * n)) / 2))
    if (a + 1) * a // 2 >= n:
        print(a)
    else:
        print(a + 1)
else:
    n -= int((h + 1) * h / 2)
    n -= h
    if n > 0:
        a = int((-2 * h - 1 + sqrt((2 * h + 1) * (2 * h + 1) + 4 * n)) / 2)
        if (2 * h + 1 + a) * a >= n:
            print(a * 2 + h + 1)
        elif (2 * h + 1 + a) * a + h + a + 1 >= n:
            print(a * 2 + 1 + h + 1)
        else:
            print(a * 2 + 2 + h + 1)
    else:
        print(h + 1)