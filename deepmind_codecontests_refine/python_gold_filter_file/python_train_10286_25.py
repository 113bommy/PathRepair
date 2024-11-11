N, *p = map(int, open(0).read().split())

if sum(p[i] != i + 1 for i in range(N)) <= 2:
    print('YES')
else:
    print('NO')