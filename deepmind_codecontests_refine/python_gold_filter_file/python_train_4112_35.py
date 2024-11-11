n, v, p = int(input()), 0, 1
while n >= 10 ** p:
    v += p * 9 * 10 ** (p - 1)
    p += 1
v += (n - 10 ** (p - 1) + 1) * p
print(v)