import math as mt

t = int(input())

while t:
    a, b, c, d, k = map(int, input().split())

    min_pen = mt.ceil(a/c)
    min_pencil = mt.ceil(b/d)

    if (min_pen + min_pencil > k):
        print(-1)
    else:
        print("{} {}".format(min_pen, min_pencil))


    t = t - 1