q = int(input())
inf = 10 ** 5
for _ in range(q):
    n = int(input())
    lx, dy = -inf, -inf
    rx, uy = inf, inf
    for k in range(n):
        t = input().split()
        x, y = map(int, t[:2])
        f = list(map(int, t[2:]))
        if f[0] == 0:
            lx = max(lx, x)
        if f[1] == 0:
            uy = min(uy, y)
        if f[2] == 0:
            rx = min(rx, x)
        if f[3] == 0:
            dy = max(dy, y)
    
    if lx > rx or dy > uy:
        print(0)
    else:
        x, y = (lx + rx) // 2, (dy + uy) // 2
        print(1, x, y)
            