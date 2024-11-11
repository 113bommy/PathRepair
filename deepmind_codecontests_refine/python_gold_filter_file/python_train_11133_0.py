while True:
    n, m = map(int, input().split())
    if n == 0:
        break
    else:
        s = 0
        l = []
        for _ in range(n):
            d, p = map(int, input().split())
            s += d * p
            l.append((p,d))

        l.sort()
        while m > 0 and l:
            a, b = l.pop()
            if m >= b:
                s -= a * b
                m -= b
            else:
                s -= a * m
                m = 0

        print(s)
