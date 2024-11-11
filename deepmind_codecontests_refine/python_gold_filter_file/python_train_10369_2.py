x, y, l, r = map(int, input().split())
rec = []
for i in range(61):
    for j in range(61):
        if l <= x ** i + y ** j <= r:
            rec.append(x ** i + y ** j)

rec.append(r + 1)
rec = sorted(set(rec))
pre = l - 1
num = 0
for i in range(len(rec)):
    num = max(num, rec[i] - pre - 1)
    pre = rec[i]
print(num)
