h1, h2 = map(int, input().split())
a, b = map(int, input().split())
day = 0
while h1 < h2:
    if day == 0:
        h1 += a * 8
        if h1 < h2 and b >= a:
            print(-1)
            break
        elif h1 < h2:
            h1 -= b * 12
            day += 1
        while h1 < h2:
            h1 += a * 12
            if h1 < h2:
                h1 -= b * 12
                day += 1
        print(day)