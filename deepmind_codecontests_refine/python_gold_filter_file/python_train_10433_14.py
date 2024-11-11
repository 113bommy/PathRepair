x0, y0, ax, ay, bx, by = map(int, input().split())
xs, ys, t = map(int, input().split())

LIM = 60

arr_xs = [x0]
for i in range(LIM * 2):
    arr_xs.append(arr_xs[i] * ax + bx)
arr_ys = [y0]
for i in range(LIM * 2):
    arr_ys.append(arr_ys[i] * ay + by)

# print(arr_xs[:5])

def dst(x1, y1, x2, y2):
    return abs(x1 - x2) + abs(y1 - y2)

ans = 0
for start in range(len(arr_ys)):
    cur_d = dst(arr_xs[start], arr_ys[start], xs, ys)
    pt = start
    if (cur_d > t): continue
    cnt = 1
    while(pt < len(arr_xs)):
        cur_d += dst(arr_xs[pt], arr_ys[pt], arr_xs[pt + 1], arr_ys[pt + 1])
        if (cur_d > t) : break
        cnt += 1
        pt += 1
    ans = max(ans, cnt)

for start in range(len(arr_xs)):
    cur_d = dst(arr_xs[start], arr_ys[start], xs, ys)
    pt = start
    if (cur_d > t): continue
    cnt = 1
    while(pt > 0):
        cur_d += dst(arr_xs[pt], arr_ys[pt], arr_xs[pt - 1], arr_ys[pt - 1])
        if (cur_d > t) : break
        cnt += 1
        pt -= 1
    ans = max(ans, cnt)
print(ans)