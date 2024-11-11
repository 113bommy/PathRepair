import math
n, k = map(int, input().split())
x = (math.sqrt(8 * n + 8 * k + 9) - 3) / 2
print(round(n - x))
