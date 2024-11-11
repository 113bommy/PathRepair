n, m, k = map(int, input().split())
x = 0; last = False
if k == 1:
    print(n * m, end=' ')
    last = True
for i in range(n):
    if i % 2:
        for j in range(m // 2 * 2 - 1, -1, -2):
            if not last:
                x += 1
                print(2, i + 1, j + 1, i + 1, j)
                if x == k - 1:
                    print(n*m - (k - 1)*2, end=' ')
                    last = True
            else:
                print(i + 1, j + 1, i + 1, j, end=' ')
    else:
        for j in range(0, m // 2 * 2, 2):
            if not last:
                x += 1
                print(2, i + 1, j + 1, i + 1, j + 2)
                if x == k - 1:
                    print(n*m - (k - 1)*2, end=' ')
                    last = True
            else:
                print(i + 1, j + 1, i + 1, j + 2, end=' ')
        if m % 2:
            if not last:
                x += 1
                print(2, i + 1, j + 3, i + 2, j + 3)
                if x == k - 1:
                    print(n*m - (k - 1)*2, end=' ')
                    last = True
            else:
                if i + 1 < n:
                    print(i + 1, j + 3, i + 2, j + 3, end=' ')
                else:
                    print(i + 1, j + 3, end=' ')
