def maxdis(cx,cy):
    global x, y
    dmax = d = 0
    xf, yf = 0, 0
    for i in range(len(x)):
        d = max(d ,((x[i] - cx) ** 2 + (y[i] -cy) ** 2) ** 0.5)
        if dmax < d:
            dmax = d
            xf, yf =x[i], y[i]
    return xf, yf

N = int(input())
x = []; y = []
for i in range(N):
    xi, yi = map(int,input().split())
    x.append(xi);y.append(yi)

cx, cy = 500, 500
r = 500 * 1.5
i=0
while (r > 10 ** -10):
    xf, yf = maxdis(cx,cy)
    df = ((xf - cx) ** 2 + (yf - cy) ** 2) ** 0.5
    r *= 0.999
    dx = r * (xf - cx) / df
    dy = r * (yf - cy) / df
    cx += dx; cy += dy
    i += 1

    # print(i, cx, cy, df, r, xf, yf)

print(df)