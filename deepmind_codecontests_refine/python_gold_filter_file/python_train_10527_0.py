from math import sqrt

n, k = map(int, input().split())
minimum = 10 ** 16 + 1
for i in range(1, int(sqrt(n)) + 1):
    if n % i == 0:
        if n // i < k:
            x = i * k + n // i
            minimum = min(minimum, x)
        if i < k:
            x = (n // i) * k + i
            minimum = min(minimum, x)
print(minimum)
