q = int(input())
for i in range(q):
    n = int(input())
    a = sorted(list(map(int, input().split())))
    s = a[0]*a[4 * n - 1]
    f = 1
    for j in range(0, 2 * n, 2):
        if a[j] * a[4 * n - 1 - j] != s or a[j] != a[j + 1] or a[4 * n - 1 - j] != a[4 * n - 2 - j]:
            f = 0
            break
    if f == 1:
        print('YES')
    else:
        print('NO')
