x, y, z, t1, t2, t3 = map(int, input().split())
stair = abs(z - x) * t2 + t3 * 3 + abs(y - x) * t2
afoot = t1 * abs(y - x)
if afoot < stair:
    print('NO')
else:
    print('YES')

