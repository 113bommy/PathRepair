import math


def dist(x1, y1, x2, y2):
    res = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)
    res = math.sqrt(res)
    return res


ax, ay, bx, by, tx, ty = list(map(int, input().split()))
n = int(input())
ans = 0
bottles = [(0, 0) for i in range(n)]
da = [(0, -1) for i in range(n + 1)]
db = [(0, -1) for i in range(n + 1)]

for i in range(n):
    xi, yi = list(map(int, input().split()))
    bottles.append((xi, yi))

    # We compute the dist from xi, yi to tx ty and add the double to the ans
    dt = dist(xi, yi, tx, ty)
    ans += 2 * dt

    # We now compute dist from ax, ay to xi, yi and dt (the path to collect the bottle and go to the center)
    dist_a = dist(ax, ay, xi, yi) - dt
    da[i] = (dist_a, i)
    # Same for b
    dist_b = dist(bx, by, xi, yi) - dt
    db[i] = (dist_b, i)

best = 10 ** 18
da = sorted(da)
db = sorted(db)

for i in range(min(3, n + 1)):
    for j in range(min(3, n + 1)):
        if da[i][1] == db[j][1]:
            continue
        if da[i][1] == -1 and db[j][1] == -1:
            continue
        best = min(best, da[i][0] + db[j][0])

print(ans + best)

# Now we just need to know if a and b can pick something up
# For that, several cases
# If both min_dist_a and min_dist_b are greater than the distance needed to collect the corresponding bottle
# Only one of them will, the one with the least distance

# If one of them has a min_dist greater than the distance needed to collect, it won't

# If both of them can collect one (less then their distance), they both do
# We suppose for now this happen all the time

# print(s)
