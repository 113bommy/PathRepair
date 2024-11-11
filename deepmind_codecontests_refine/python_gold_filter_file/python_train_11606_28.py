n = int(input())
matrix = [[0 for i in range(n)]for j in range(n)]
if n==1:
    print(1)
else:
    for i in range(n):
        matrix[0][i]=1
        matrix[1][i]=i+1
        for j in range(2,n):
            if i ==0:
                matrix[j][0]=1
            else:
                matrix[j][i]=matrix[j][i-1]+matrix[j-1][i]
    print(matrix[n-1][n-1])