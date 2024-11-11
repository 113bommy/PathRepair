while True:
    n, m = map(int, input().split())
    if n == 0:
        break
    risks = [(p, d) for d, p in (map(int, input().split()) for _ in range(n))]
    risks.sort()
    remain = 0
    while risks:
        p, d = risks.pop()
        if d >= m:
            remain = p * (d - m)
            break
        m -= d
    print(remain + sum(p * d for p, d in risks))