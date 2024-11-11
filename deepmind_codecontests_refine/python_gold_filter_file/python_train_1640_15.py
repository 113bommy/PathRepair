from math import ceil

n, m, a, b = map(int, input().split())
print(min((ceil(n / m) * m - n) * a, (n - (n // m) * m) * b))
# CodeForcesian
# ♥
