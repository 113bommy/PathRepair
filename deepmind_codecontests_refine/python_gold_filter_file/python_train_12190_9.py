n, m = [int(i) for i in input().split()]

res = 0


def arith_prog(n):
    return n * (n - 1) // 2


a = arith_prog(n)
b = 2 * arith_prog(((n - 1) // 2) + 1)
if n % 2 == 0:
    b += n // 2

for it in range(m):
    x, d = [int(i) for i in input().split()]
    res += x * n
    if d > 0:
        res += a * d
    else:
        res += b * d

print(res / n)
