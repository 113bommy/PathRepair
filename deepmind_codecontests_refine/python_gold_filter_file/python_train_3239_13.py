import math
n, m = map(int, input().split())
x = 0
for i in range(2, n + 1):
    if i * (i - 1) < 2 * m:
        x = i + 1
    elif i * (i - 1) == 2 * m:
        x = i
    else:
        break

print(max(0, n - m * 2), n - x)