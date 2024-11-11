def arr_inp():
    return [int(x) for x in input().split()]


def arr_2d(n, m):
    return [[1 for x in range(m)] for i in range(n)]


def print_arr(arr):
    print(*arr, sep='')


matrix = arr_2d(3, 3)

for i in range(3):
    x = arr_inp()
    for j in range(3):
        if (x[j] % 2):
            if (j > 0):
                matrix[i][j - 1] = 1 - (matrix[i][j - 1])
            if (j < 2):
                matrix[i][j + 1] = 1 - (matrix[i][j + 1])
            if (i > 0):
                matrix[i - 1][j] = 1 - (matrix[i - 1][j])
            if (i < 2):
                matrix[i + 1][j] = 1 - (matrix[i + 1][j])
            matrix[i][j] = 1 - (matrix[i][j])
for i in range(3):
    print_arr(matrix[i])
