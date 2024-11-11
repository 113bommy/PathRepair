for _ in range(int(input())):
    cnt = 0
    a, b, c = map(int, input().split())
    if a < b:
        a, b = b, a
    if b < c:
        b, c = c, b
    if a < b:
        a, b = b, a
    if a > 0:
        a -= 1
        cnt += 1
    if b > 0:
        b -= 1
        cnt += 1
    if c > 0:
        c -= 1
        cnt += 1
    if a > 0 and b > 0:
        cnt += 1
        a -= 1
        b -= 1
    if c > 0 and a > 0:
        cnt += 1
        c -= 1
        a -= 1
    if b > 0 and c > 0:
        cnt += 1
        b -= 1
        c -= 1

    if a > 0 and b > 0 and c > 0:
        cnt += 1
    print(cnt)
