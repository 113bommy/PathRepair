from math import pi, sin
n, R, r = map(int, input().split())
print('NO' if r > R or (n > 1 and ((R - r) * sin(pi / n) + 1e-9) < r) else 'YES')
