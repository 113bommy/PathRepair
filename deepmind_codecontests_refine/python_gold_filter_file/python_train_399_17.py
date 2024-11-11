import math
n, x = map(int, input().split())
print(3 * (n - math.gcd(n, x)))
