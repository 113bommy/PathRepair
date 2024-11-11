for _ in range(int(input())):
    n = int(input())
    m = 1
    c = 1
    d = 0
    l = []
    while m != n:
        if 2 * c + m >= n:
            l.append(n - (m + c))
            d += 1
            break
        l.append(min(c, (n - m - 2 * c) // 2))
        c += min(c, (n - m - 2 * c) // 2)
        m += c
        d += 1
    print(d)
    print(*l)