import sys
for i in sys.stdin:
    a, b, c, d, e, f = map(int, i.split())
    x = (c * e - b * f) / (a * e - b * d)
    y = (c * d - a * f) / (b * d - a * e)
    x = abs(x) if abs(x) < 10e-4 else x
    y = abs(y) if abs(y) < 10e-4 else y
    print("{:.3f} {:.3f}".format(x, y))
