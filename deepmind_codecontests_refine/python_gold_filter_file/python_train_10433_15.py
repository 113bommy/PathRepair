x, y, ax, ay, bx, by = map(int, input().split())

xs, ys, t = map(int, input().split())

xx = []

xx.append(x)
x1 = ax * x + bx

while len(xx) < 1000:
    xx.append(x1)
    x1 = ax * x1 + bx

yy = []

yy.append(y)
y1 = ay * y + by

while len(yy) < 1000:
    yy.append(y1)
    y1 = ay * y1 + by



n = 1000

ans = 0
for i in range(n):
    r1 = abs(xx[i] - xs) + abs(yy[i] - ys)
    if r1 > t:
        continue
    cnt = 1
    for j1 in range(1, i + 1):
        j = i - j1
        r1 += abs(xx[j] - xx[j + 1]) + abs(yy[j] - yy[j + 1])
        if r1 > t:
            break
        cnt += 1

    ans = max(ans, cnt)

    if i + 1 < 1000:
        r1 += abs(xx[i + 1] - xx[0]) + abs(yy[i + 1] - yy[0])
        if r1 > t:
            continue
        cnt += 1
        for j in range(i + 2, n):
            r1 += abs(xx[j] - xx[j - 1]) + abs(yy[j] - yy[j - 1])
            if r1 > t:
                break
            cnt += 1
        ans = max(ans, cnt)
print(ans)

