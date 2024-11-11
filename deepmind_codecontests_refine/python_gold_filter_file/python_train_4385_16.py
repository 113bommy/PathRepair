[x, y, z, t1, t2, t3] = [int(t) for t in input().split(' ')]

if (abs(z - x) + abs(x - y)) * t2 + t3 * 3 <= abs(x-y) * t1:
    print('YES')
else:
    print('NO')
