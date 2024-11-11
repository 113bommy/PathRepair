while True:
    n, m = map(int, input().split())
    if n == 0 and m == 0:
        break
    sections = []
    for i in range(n):
        d, p = map(int, input().split())
        sections.append([p, d])
    sections.sort()
    sections.reverse()

    e = 0
    for p, d in sections:
        if d <= m:
            m -= d
            d = 0
        elif m > 0:
            d -= m
            m = 0
        e += p * d
    print(e)