matrix = []
for i in range(3):
    ls = list(map(int, input().split()))
    matrix.append(ls)
for i in range(3):
    for j in range(3):
        presses = matrix[i][j]
        if j+1 < 3:
            presses += matrix[i][j+1]
        if j-1 >= 0:
            presses += matrix[i][j-1]
        if i+1 < 3:
            presses += matrix[i+1][j]
        if i-1 >= 0:
            presses += matrix[i-1][j]
        if presses % 2 == 0:
            print(1, end="")
        else:
            print(0, end="")
    print()