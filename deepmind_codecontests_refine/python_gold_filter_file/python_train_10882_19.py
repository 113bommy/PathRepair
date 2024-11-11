n, m = map(int, input().split())

xs = list(map(int, input().split()))
ys = []

t = 0


def ans():
    print(len(ys))
    print(' '.join(list(map(str, ys))))
    exit()

xs.append(0)

xs.sort()

for i in range(n):
    for j in range(xs[i] + 1, xs[i + 1]):
        t += j
        if t <= m:
            ys.append(j)
        else:
            ans()

for h in range(xs[-1] + 1, 1000000001):
    t += h
    if t <= m:
        ys.append(h)
    else:
        ans()

ans()
