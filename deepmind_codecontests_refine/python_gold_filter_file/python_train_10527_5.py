a = [int(i) for i in input().split()]
n, k = a[0], a[1]
divider = -1
for i in range(n // k, n):
    if n % (i + 1) == 0:
        divider = n // (i + 1)
        break
print(k * n // divider + divider)
