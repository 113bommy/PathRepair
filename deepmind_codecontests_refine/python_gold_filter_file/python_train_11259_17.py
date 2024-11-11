import math

n, t = map(int, input().split())
all = []
for each in range(n):
    s, d = tuple(map(int, input().split()))
    if t > s:
        koef = math.ceil((t - s) / d) * d - t + s
    else:
        koef = s - t
    all.append(koef)
mi = min(all)
for each in range(n):
    if all[each] == mi:
        print(each + 1)
        exit()
