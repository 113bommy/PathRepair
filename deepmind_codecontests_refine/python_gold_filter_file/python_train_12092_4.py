from math import gcd

n, k = map(int, input().split())
a, b = map(int, input().split())
x, y = float('inf'), -float('inf')
m = n * k
for f, s in [1, 1], [-1, -1], [1, -1], [-1, 1]:
    for r in range(2, n + 5):
        val = r * k + b * f + a * s
        dist = m * val // gcd(m, val)
        stops = dist // val
        x = min(x, stops)
        y = max(y, stops)
print(x, y)
