def dist(x1, y1, x2, y2):
    return abs(x1 - x2) + abs(y1 - y2)


x0, y0, ax, ay, bx, by = map(int, input().split())
xs, ys, t = map(int, input().split())
num = []
num.append([x0, y0])
for i in range(200):
    kek = num[-1];
    lol = [kek[0] * ax + bx, kek[1] * ay + by]
    num.append(lol)
    if lol[0] >  10 ** 30 and lol[1] > 10 ** 30:
        break
ans = 0
for i in range(len(num)):
    x = 0;
    y = 0;
    x += xs
    y += ys
    res = dist(x, y, num[i][0], num[i][1])
    nxt = i + 1
    x = num[i][0]
    y = num[i][1]
    kek = 0
    while res <= t and nxt < len(num):
        kek += 1;
        res += dist(x, y, num[nxt][0], num[nxt][1]);
        x = num[nxt][0]
        y = num[nxt][1]
        nxt += 1
    if res <= t:
        kek += 1
   # if i == 0:
    #    print(kek, 'a')
    x = 0
    y = 0
    x += xs
    y += ys
    ans = max(ans, kek)
    nxt = i - 1
    res = dist(x, y, num[i][0], num[i][1])
    x = num[i][0]
    y = num[i][1]
    kek = 0
    while res <= t and nxt >= 0:
        kek += 1;
        res += dist(x, y, num[nxt][0], num[nxt][1]);
        x = num[nxt][0]
        y = num[nxt][1]
        nxt -= 1
    if res <= t:
        kek += 1
    ans = max(ans, kek)
print(ans)