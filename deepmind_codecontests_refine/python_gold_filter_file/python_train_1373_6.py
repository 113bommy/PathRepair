x1, y1, x2, y2 = map(int, input().split(' '))
x3, y3, x4, y4 = map(int, input().split(' '))
x5, y5, x6, y6 = map(int, input().split(' '))


def sp(x1, x2, x3, x4, y1, y2, y3, y4):
    if x2 > x4:
        f_px = x4
    else:
        f_px = x2
    if x1 > x3:
        s_px = x1
    else:
        s_px = x3
    if y4 > y2:
        f_py = y2
    else:
        f_py = y4
    if y1 > y3:
        s_py = y1
    else:
        s_py = y3
    l = f_px - s_px
    if l < 0:
        l = 0
    h = f_py - s_py
    if h < 0:
        h = 0
    return f_px, s_px, f_py, s_py, l * h


s_w = (x2 - x1) * (y2 - y1)
f1, s1, f2, s2, s_b1 = sp(x1, x2, x3, x4, y1, y2, y3, y4)
f3, s3, f4, s4, s_b2 = sp(x1, x2, x5, x6, y1, y2, y5, y6)
aa, aaa, aaaa, aaaaa, s_b3 = sp(s1, f1, s3, f3, s2, f2, s4, f4)
if s_w > s_b2 + s_b1 - s_b3:
    print('YES')
else:
    print('NO')
