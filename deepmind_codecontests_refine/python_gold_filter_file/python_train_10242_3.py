# import sys
# sys.stdin = open('input.txt', 'r')
# sys.stdout = open('output.txt', 'w')

matrix = []

def toggle(key):
    if key == 0:
        return 1
    else:
        return 0

for _ in range(3):
    row = list(map(int, input().split(" ")))
    matrix.append(row)

cpy_matrix = [[ 1 for i in range(3) ] for j in range(3) ]

for i in range(3):
    for j in range(3):
        ways = [
            [i+1, j],
            [i-1, j],
            [i, j+1],
            [i, j-1]
            # [i+1, j+1],
            # [i+1, j-1],
            # [i-1, j+1],
            # [i-1, j-1],
        ]

        if matrix[i][j]%2 != 0:
            for key, value in ways:
                if 0<= key < 3 and 0 <= value < 3:
                    cpy_matrix[key][value] = toggle(cpy_matrix[key][value])
            cpy_matrix[i][j] = toggle(cpy_matrix[i][j])


for i in range(3):
    for j in range(3):
        print(cpy_matrix[i][j],end='')
    print()



