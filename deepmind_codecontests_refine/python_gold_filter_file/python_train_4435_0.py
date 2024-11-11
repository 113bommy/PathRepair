n, h = map(int, input().split())
s = h / 2
p = s / n
b = 1
c = 0
t = 1 / (2 * h)
res = []
for i in range(n - 1):
    l = c
    r = h
    while r - l > 10 ** -10:
        m = (l + r) / 2
        if (m - c) * (b - t * (m - c)) >= p:
            r = m
        else:
            l = m
    res.append(l)
    b -= 2 * t * (l - c)
    c = l
for i in range(n - 2, -1, -1):
    print(h - res[i], end=' ')

