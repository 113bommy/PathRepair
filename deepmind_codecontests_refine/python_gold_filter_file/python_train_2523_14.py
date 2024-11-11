for _ in range(int(input())):
    n, m = map(int, input().split())
    a, b = map(int, input().split())
    if n < m:
        n, m = m, n
    if 2 * a < b:
        print(abs(n) * a + abs(m) * a)
    else:
        if n < 0:
            n, m = -n, -m
        print((n - m) * a + min(abs(n), abs(m)) * b)