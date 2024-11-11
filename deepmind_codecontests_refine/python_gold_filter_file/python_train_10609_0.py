while True:
    n, q = map(int, input().split())
    if n == 0:
        break

    data = [list(map(int, input().split())) for i in range(n)]
    for li in data:
        if li[0] > 0:
            del(li[0])

    q -= 1
    day = 0
    for d in range(1,100):
        cnt = 0
        for li in data:
            if d in li:
                cnt += 1
        if cnt > q:
            q = cnt
            day = d

    print(day)
