n = int(input())
xy = [list(map(int, input().split())) for _ in range(n)]

dist_max = 0
for i, (x, y) in enumerate(xy):
    dist = abs(x) + abs(y)
    if i == 0:
        parity = dist%2
    else:
        if dist%2 != parity:
            print(-1)
            exit()

    if parity == 0:
        x -= 1
        dist = abs(x) + abs(y)

    dist_max = max(dist_max, dist)
    xy[i] = [x, y]

d = []
d_i = 1
for i in range(40):
    if d_i > dist_max:
        break
    d.append(d_i)
    d_i *= 2
d = sorted(d, reverse = True)
if parity == 0:
    d.append(1)

print(len(d))
print(' '.join(map(str, d)))

for x, y in xy:
    ans = ''
    prev = 0
    for d_i in d:
        if prev == d_i and d_i == 1:
            ans += 'R'
            break
        if x+y < 0:
            if x-y < 0:
                ans += 'L'
                x += d_i
            else:
                ans += 'D'
                y += d_i
        else:
            if x-y < 0:
                ans += 'U'
                y -= d_i
            else:
                ans += 'R'
                x -= d_i
        prev = d_i
    print(ans)
