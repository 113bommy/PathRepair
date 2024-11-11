import math

a, b, x = map(int, input().split())
ret = (b - x / a**2) * 2 / a if a**2 * b <= 2 * x else  a * b**2 / (2 * x)
print(math.degrees(math.atan(ret)))