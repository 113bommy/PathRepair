n = int(input())
a = 0
b = n
while b - a != 1:
    k = (a + b) // 2
    c = n
    d = 0
    while c > 0:
        m = min(k, c)
        c -= m
        c -= c // 10
        d += m
    if 2 * d >= n:
        b = k
    else:
        a = k
print(b)
