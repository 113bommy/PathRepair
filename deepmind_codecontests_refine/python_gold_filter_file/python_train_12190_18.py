n, m = [int(i) for i in input().split()]
n2 = n // 2

mi = (n2) * (n2 + 1)
ma = (n * (n - 1)) // 2

if n % 2 == 0:
    mi -= n2

avg = 0
for i in range(int(m)):
    x, d = [int(i) for i in input().split()]
    if d < 0:
        avg += (d * mi) + x * n
    else:
        avg += (d * ma) + x * n

print(avg / n)
