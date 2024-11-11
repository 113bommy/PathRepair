from math import gcd
n, k = map(int, input().split())
a, b = map(int, input().split())
x, y = int(1e15), -1
for i in range(1, n + 1):
    for v in a - b, a + b, b - a, - a - b:
        l = k * i + v % k
        g = gcd(n * k, l)
        x = min(x, n * k // g)
        y = max(y, n * k // g)
print(x, y)
