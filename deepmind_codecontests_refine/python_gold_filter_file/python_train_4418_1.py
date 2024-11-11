def printMat(matrix):
    for i in range(n):
        for j in range(n):
            print("{:.8f}".format(matrix[i][j]), end = " ")

        print()


n = int(input())
mat = []

for k in range(0, n):
    mat.append(list(map(int, input().rstrip().split())))

A = mat
B = [[0] * n for _ in range(n)]

for i in range(1, n):
    for j in range(0, i):
        
        a = (mat[i][j] + mat[j][i]) / 2
        b = mat[j][i] - a

        A[i][j] = a
        B[i][j] = -b
        A[j][i] = a
        B[j][i] = b


printMat(A)
printMat(B)