x1, y1, x2, y2, x3, y3 = map(int, input().split())

p = [[x1, y1], [x2, y2], [x3, y3]]

d = (1, -1)

a = [0] * 3
for i in range(3):
    a[i] = (p[i][0] - p[i - 1][0]) ** 2 + (p[i][1] - p[i - 1][1]) ** 2
a.sort()
if abs(a[2] ** 0.5 - a[1] ** 0.5 - a[0] ** 0.5) > 0.001 and a[0] + a[1] == a[2]:
    print("RIGHT")
else:
    ok = False
    for i in range(3):
        for j in range(2):
            for k in range(2):
                p[i][j] += d[k]
                a = [0] * 3
                for l in range(3):
                    a[l] = (p[l][0] - p[l - 1][0]) ** 2 + (p[l][1] - p[l - 1][1]) ** 2
                a.sort()
                if abs(a[2] ** 0.5 - a[1] ** 0.5 - a[0] ** 0.5) > 0.001 and a[0] + a[1] == a[2]:
                    ok = True
                p[i][j] -= d[k]
    print("ALMOST" if ok else "NEITHER")
                