from math import sqrt

n, k = map(int, input().split())
ms = 2 * 1e9
for i in range(1, int(sqrt(n)) + 2):
    if n % i == 0:
        t = n // i
        for j in range(k * i, k * (i + 1)):
            if j % k == t:
                ms = min(j, ms)
                break
        for j in range(k * t, k * (t + 1)):
            if j % k == i:
                ms = min(j, ms)
                break
print(int(ms))
