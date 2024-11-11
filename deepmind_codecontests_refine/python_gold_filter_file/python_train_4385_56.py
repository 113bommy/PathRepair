x, y, z, t1, t2, t3 = map(int, input().split())

n1 = t2 * abs(x - y) + t2 * abs(x - z) + t3 * 3
n2 = t1 * abs(x - y)

if n1 <= n2:
    print('YES')
else:
    print('NO')