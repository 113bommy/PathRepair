x, y, z, t1, t2, t3 = map(int, input().split())
t_step = abs(x - y) * t1
t_lift = (abs(x - z) + abs(x - y)) * t2 + t3 * 3
if t_lift <= t_step:
    print('YES')
else:
    print('NO')