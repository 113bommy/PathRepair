n, m, k = map(int, input().split(' '))
field = [[0 for y in range(m + 1)] for x in range(n + 1)]
for step in range(k):
    i, j = map(int, input().split(' '))
    i -= 1
    j -= 1
    field[i][j] = 1
    if i > 0 and j > 0 and field[i][j - 1] == 1 and field[i - 1][j] == 1 and field[i - 1][j - 1] == 1:
        print(step + 1)
        break
    elif i < n - 1 and j < m - 1 and field[i][j + 1] == 1 and field[i + 1][j] == 1 and field[i + 1][j + 1] == 1:
        print(step + 1)
        break
    elif i > 0 and j < m - 1 and field[i - 1][j] == 1 and field[i][j + 1] == 1 and field[i - 1][j + 1] == 1:
        print(step + 1)
        break
    elif i < n - 1 and j > 0 and field[i][j - 1] == 1 and field[i + 1][j] == 1 and field[i + 1][j - 1] == 1:
        print(step + 1)
        break
else: print('0')