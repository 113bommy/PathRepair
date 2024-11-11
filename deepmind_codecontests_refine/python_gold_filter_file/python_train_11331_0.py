k = int(input())
d, m = divmod(k, 50)
b = 49 + d
print(50)
print(*map(str, [b + 1] * m + [b - m] * (50 - m)))
