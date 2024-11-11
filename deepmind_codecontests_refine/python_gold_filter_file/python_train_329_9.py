n, p, w, d = map(int, input().split())
r = p % w
n1 = 0
for i in range(1, 100000):
    if (d * i) % w == r:
        n1 = i
        break
n2 = (p - d * n1) // w
n3 = 0
r1 = p % d
for i in range(1, 100000):
    if (w * i) % d == r1:
        n3 = i
        break
n4 = (p - w * n3) // d
if p == 0:
    print(0, 0, n)
elif p % w == 0 and p // w <= n:
    print(p // w, 0, n - p // w)
elif p % d == 0 and p // d <= n:
    print(0, p // d, n - p // d)
elif n2 >= 0 and n1 * d + n2 * w == p and n1 + n2 <= n:
    print(n2, n1, n - n1 - n2)
elif n4 >= 0 and n3 * w + n4 * d == p and n3 + n4 <= n:
    print(n3, n4, n - n3 - n4)
else:
    print(-1)