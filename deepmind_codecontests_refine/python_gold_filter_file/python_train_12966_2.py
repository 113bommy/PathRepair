n, m = map(int, input().split(' '))
rows = [0] * n
columns = [0] * n
r = c = n
for i in range(0, m):
    x, y = map(int, input().split(' '))
    x = x - 1
    y = y - 1
    if rows[x] == 0:
        r = r - 1
    if columns[y] == 0:
        c = c - 1
    rows[x] = 1
    columns[y] = 1
    print(r * c)
