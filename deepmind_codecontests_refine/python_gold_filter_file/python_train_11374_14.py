#!/usr/bin/env python3
nb_test = int(input())
for t in range(nb_test):
    n, m = [int(x) for x in input().split()]
    matrix = [[0 for x in range(m)] for y in range(n)]

    # Créer la matrice
    for a in range(n):
        matrix[a] = [int(x) for x in input().split()]

    # Transposer si plus de lignes
    if (n > m):
        matrix_t = [[0 for x in range(n)] for y in range(m)]
        for i in range(n):
            for j in range(m):
                matrix_t[j][i] = matrix[i][j]
        matrix = matrix_t.copy()
        temp = n
        n = m
        m = temp

    min_cell = 0

    # Small diagonal
    for i in range(n-1):
        sum_cell = 0
        for d in range(i+1):
            sum_cell += matrix[d][i-d]
            sum_cell += matrix[n-d-1][m-(i-d)-1]
        min_cell += min(sum_cell, 2*(i+1)-sum_cell)

    # Long diagonal
    for i in range(n-1,n-1+int((m-(n-1))/2)):
        sum_cell = 0
        for d in range(n):
            sum_cell += matrix[d][i-d]
            sum_cell += matrix[n-d-1][m-(i-d)-1]
        min_cell += min(sum_cell, 2*n-sum_cell)

    print(min_cell)
