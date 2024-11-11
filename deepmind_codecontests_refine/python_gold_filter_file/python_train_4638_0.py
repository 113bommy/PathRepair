n = int(input())
snitch = [ tuple(map(int, input().split())) for i in range(n + 1) ]
v_potter, v_snitch = map(int, input().split())
potter = tuple(map(int, input().split()))
xp, yp, zp = potter

t_snitch_before = 0

for i in range(1, n + 1):
    #print(i, t_snitch_before)
    x0, y0, z0 = snitch[i - 1]
    x1, y1, z1 = snitch[i]
    d_snitch = ((x1 - x0) ** 2 + (y1 - y0) ** 2 + (z1 - z0) ** 2) ** 0.5
    t_snitch = t_snitch_before + d_snitch / v_snitch
    #print(i, t_snitch_before, t_snitch)
    d_potter = ((x1 - xp) ** 2 + (y1 - yp) ** 2 + (z1 - zp) ** 2) ** 0.5
    t_potter = d_potter / v_potter
    if t_potter <= t_snitch:
        xl, yl, zl = x0, y0, z0
        xh, yh, zh = x1, y1, z1
        count = 0
        while abs(t_potter - t_snitch) > 1e-11:
            #print(xl, yl, zl, xh, yh, zh, abs(t_potter - t_snitch))
            xm, ym, zm = (xl + xh) / 2, (yl + yh) / 2, (zl + zh) / 2
            d_snitch = ((xm - x0) ** 2 + (ym - y0) ** 2 + (zm - z0) ** 2) ** 0.5
            t_snitch = t_snitch_before + d_snitch / v_snitch
            d_potter = ((xm - xp) ** 2 + (ym - yp) ** 2 + (zm - zp) ** 2) ** 0.5
            t_potter = d_potter / v_potter
            #print(xm, ym, zm, t_snitch, t_potter)
            if t_potter <= t_snitch:
                xh, yh, zh = xm, ym, zm
            else:
                xl, yl, zl = xm, ym, zm
        print('YES')
        print('%.7f' % t_potter)
        print('%.7f %.7f %.7f' % (xh, yh, zh))
        import sys; sys.exit()
    t_snitch_before = t_snitch
print('NO')
