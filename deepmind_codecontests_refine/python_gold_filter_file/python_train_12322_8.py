n = int(input())

ans = 10 ** 18

def f(x):
    s = 0
    while x > 0:
        s += x % 10
        x //= 10
    return s

def sqr(x):
    l, r = 0, 10 ** 10
    while r > l + 1:
        m = (l + r) // 2;
        if m * m <= x:
            l = m
        else:
            r = m
    return l

for s in range(100):
    if sqr(s ** 2 + 4 * n) ** 2 == s ** 2 + 4 * n:
        x1 = (-s + sqr(s ** 2 + 4 * n)) / 2
        x2 = (-s - sqr(s ** 2 + 4 * n)) / 2
        if x1 > 0 and int(x1) == x1 and f(int(x1)) == s:
            ans = min(ans, int(x1))
        if x2 > 0 and int(x2) == x2 and f(int(x2)) == s:
            ans = min(ans, int(x2))

if ans == 10 ** 18:
    print(-1)
else:
    print(ans)