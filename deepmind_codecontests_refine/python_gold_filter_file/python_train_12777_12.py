a, b, c, d = map(int, input().split())
res = [['A'] * 50 for i in range(25)] + [['B'] * 50 for i in range(25)]
a, b = a - 1, b - 1
for i in range(0, 24, 2):
    for j in range(0, 50, 2):
        if b > 0:
            b -= 1
            res[i][j] = 'B'
        elif c > 0:
            c -= 1
            res[i][j] = 'C'
        elif d > 0:
            d -= 1
            res[i][j] = 'D'
        if a > 0:
            a -= 1
            res[i + 26][j] = 'A'
print(50, 50)
for i in res:
    print(*i, sep='')