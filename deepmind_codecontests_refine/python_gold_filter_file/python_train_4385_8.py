inputs = [int(s) for s in input().split()]
x, y, z, t1, t2, t3 = inputs[0], inputs[1], inputs[2], inputs[3], inputs[4], inputs[5]
time_without_lift  = abs(x - y) * t1
time_with_lift = abs(z - x) * t2 + 3 * t3 + abs(x - y) * t2
if time_with_lift <= time_without_lift:
    print('YES')
else:
    print('NO')
