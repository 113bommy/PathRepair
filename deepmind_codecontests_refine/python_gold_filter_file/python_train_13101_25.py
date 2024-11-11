n, c, k = map(int, input().split())
T = sorted([int(input()) for _ in range(n)])

out = T.pop(0) + k
peo = 1
bus = 1

for t in T:
    if t <= out and peo < c:
        peo += 1

    else:
        out = t + k
        peo = 1
        bus += 1

print(bus)