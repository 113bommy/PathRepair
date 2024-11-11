from math import ceil
k, a, b, v = map(int, input().split())
x = b // (k - 1)
ost = b % (k - 1)
n = v * k
if x * n >= a:
    print(ceil(a / (k * v)))
else:
    d = x
    a -= x * n
    if (ost + 1) * v >= a:
        print(d + 1)
    else:
        d += 1
        a -= (ost + 1) * v
        print(d + ceil(a / v))