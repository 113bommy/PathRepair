import sys
for line in sys.stdin:
    a, b, c, d, e, f = map(float, line.split())
    print('{0:.3f} {1:.3f}'.format(
        (e * c - f * b) / (e * a - d * b) + 0, (d * c - f * a) / (d * b - e * a) + 0))