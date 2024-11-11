from math import ceil

h1, h2 = map(int, input().split())
a, b = map(int, input().split())
d = max(0, h2 - h1 - 8 * a)
if d == 0:
    print(0)
elif b >= a:
    print(-1)
else:
    print(ceil(d / (12 * (a - b))))
