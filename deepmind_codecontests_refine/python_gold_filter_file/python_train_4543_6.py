def pow_h(base, degree, module=int(1e9 + 7)):
    degree = bin(degree)[2:]
    r = 1

    for i in range(len(degree) - 1, -1, -1):
        r = (r * base ** int(degree[i])) % module
        base = (base ** 2) % module

    return r

n, m, k = map(int, input().split())
# n, m, k = 1, 4, -1

if (n > m):
    n, m = m, n

if (k == -1 and (m % 2 != n % 2)):
    print(0)
else:
    print(pow_h(2, (n - 1) * (m - 1)) % int(1e9 + 7))
