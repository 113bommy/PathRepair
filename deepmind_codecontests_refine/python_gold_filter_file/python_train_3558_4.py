n, m = map(int, input().split())
matrixA = []
matrixB = []
for i in range(n):
    matrixA.append(list(map(int, input().split())))
#CHECKING IF POSSIBLE
matrixC = [[0]*(m+2)]
for i in range(n):
    matrixC.append([0]+matrixA[i]+[0])
matrixC.append([0]*(m+2))
for i in range(1,n+1):
    for j in range(1,m+1):
        if matrixC[i][j] == 1:
            sum1 = matrixC[i-1][j-1] + matrixC[i][j-1] + matrixC[i-1][j] + matrixC[i][j]
            sum2 = matrixC[i][j-1] + matrixC[i][j] + matrixC[i+1][j-1] + matrixC[i+1][j]
            sum3 = matrixC[i-1][j] + matrixC[i-1][j+1] + matrixC[i][j+1] + matrixC[i][j]
            sum4 = matrixC[i+1][j] + matrixC[i+1][j+1] + matrixC[i][j+1] + matrixC[i][j]
            if sum1 != 4 and sum2 != 4 and sum3 != 4 and sum4 != 4:
                print(-1)
                exit(0)
#COUNT
op = []
count = 0
for i in range(n-1):
    for j in range(m-1):
        if matrixA[i][j] == 1 and matrixA[i+1][j] == 1 and matrixA[i][j+1] == 1 and matrixA[i+1][j+1] == 1:
            count += 1
            op.append([i+1, j+1])
print(count)
for i in op:
    print(i[0], i[1])