n, m, a = map(int, input().split())
g = int()
k = 0
l = 0
if a == 1:
    print(n * m)
else:
    while g < m:
        g += a
        k += 1
    g = 0
    while g < n:
        g += a
        l += 1
    print(k * l)