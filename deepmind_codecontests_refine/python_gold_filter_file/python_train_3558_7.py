a, b = [int(i) for i in input().split()]
matrix = []
initial = []
for i in range(a):
    matrix.append([int(x) for x in input().split()])
    initial.append([0]*b)


def fun(matrix):
    count = 0
    result = []
    for i in range(a):
        for x in range(b):
            if matrix[i][x] == 1:
                if i < a-1 and x < b-1 and matrix[i][x+1] == 1 and matrix[i+1][x] == 1 and matrix[i+1][x+1] == 1:
                    count += 1
                    result.append([i, x])
                elif i > 0 and x < b-1 and matrix[i][x+1] == 1 and matrix[i-1][x] == 1 and matrix[i-1][x+1] == 1:
                    count += 1
                    result.append([i-1, x])
                elif i > 0 and x > 0 and matrix[i][x-1] == 1 and matrix[i-1][x] == 1 and matrix[i-1][x-1] == 1:
                    count += 1
                    result.append([i-1, x-1])
                elif i < a-1 and x > 0 and matrix[i][x-1] == 1 and matrix[i+1][x-1] == 1 and matrix[i+1][x] == 1:
                    count += 1
                    result.append([i, x-1])
                else:
                    print(-1)
                    return
    print(count)
    for i in result:
        print(i[0]+1, i[1]+1)


fun(matrix)
