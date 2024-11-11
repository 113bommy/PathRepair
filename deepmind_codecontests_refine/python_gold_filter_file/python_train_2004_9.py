t = int(input())
for _ in range(t):
    n, m, a, b = [int(ipt) for ipt in input().split()]
    if a * n != b * m:
        print('NO')
        continue
    if a < b:
        flip = True
        n, m, a, b = m, n, b, a
    else:
        flip = False
    ret = [['0'] * m for _ in range(n)]
    d = a
    for i in range(n):
        for j in range(i * d, i * d + a):
            ret[i][j % m] = '1'
    print('YES')
    if flip:
        for j in range(m):
            print(''.join([ret[i][j] for i in range(n)]))
    else:
        for i in range(n):
            print(''.join([ret[i][j] for j in range(m)]))
