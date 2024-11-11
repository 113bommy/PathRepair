import math


def dist(p_x, p_y, p0_x, p0_y, p1_x, p1_y):
    v_x = p1_x - p0_x
    v_y = p1_y - p0_y
    w_x = p_x - p0_x
    w_y = p_y - p0_y
    c1 = w_x * v_x + w_y * v_y
    if c1 <= 0:
        return math.hypot(p_x - p0_x, p_y - p0_y)
    c2 = v_x * v_x + v_y * v_y
    if c2 <= c1:
        return math.hypot(p_x - p1_x, p_y - p1_y)
    b = c1 / c2
    pb_x = p0_x + b * v_x
    pb_y = p0_y + b * v_y
    return math.hypot(p_x - pb_x, p_y - pb_y)

r_max = 0
r_min = 1000000000
n, x0, y0 = [int(i) for i in input().split()]
x0 = float(x0)
y0 = float(y0)
x_prev, y_prev = input().split()
x_initial = x_prev = float(x_prev)
y_initial = y_prev = float(y_prev)
r_prev = math.hypot(x_prev - x0, y_prev - y0)
r_max = max(r_max, r_prev)
for i in range(n):
    if i < n - 1:
        x1, y1 = input().split()
        x1 = float(x1)
        y1 = float(y1)
    else:
        x1 = x_initial
        y1 = y_initial
    dx = x1 - x0
    dy = y1 - y0
    r = math.hypot(dx, dy)
    r_max = max(r_max, r)

    # w_x = x0 - x_prev
    # w_y = y0 - y_prev
    # v_x = x1 - x_prev
    # v_y = y1 - y_prev
    # dist = fabs(v_x * w_y - v_y * w_x) / math.hypot(v_x, v_y)
    # dist1 = max(min(r, r_prev)

    d = dist(x0, y0, x_prev, y_prev, x1, y1)
    # print('d', d)
    r_min = min(r_min, d)

    x_prev = x1
    y_prev = y1
    r_prev = r

print(math.pi * (r_max * r_max - r_min * r_min))
