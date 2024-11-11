n, k, p, x, y = map(int, input().split())
a = list(map(int, input().split()))
r = 0
for i in a:
    if i >= y:
        r += 1
r = max(n // 2 + 1 - r, 0)
suma = sum(v for v in a)
if suma + r * y + (n - r - k) > x or k + r > n: print(-1)
else:
    for i in range(r): print(y, end=' ')
    for i in range(n - r - k): print(1, end=' ')
    print()

