from math import factorial as fac
n = int(input())
a = 24 * (4 ** (n-3)) + (n - 3) * 36 * (4 ** (n-4))
print(int(a))
