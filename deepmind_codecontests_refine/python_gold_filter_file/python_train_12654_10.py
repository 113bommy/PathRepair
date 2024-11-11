n = int(input())
matrix = []
for i in range(n):
    matrix.append([int(i) for i in input().split()])
zero_col = zero_row = 0
if n == 1:
    print(1)
else:
    for i in range(n):
        for j in range(n):
            if matrix[i][j] == 0:
                zero_col = j
                zero_row = i
    cur = (zero_row + 1) % n
    ans = 0
    for i in range(n):
        ans += matrix[cur][i]
    a1 = 0
    for i in range(n):
        a1 += matrix[zero_row][i]
    rem = ans - a1
    matrix[zero_row][zero_col] = rem
    flag = 0
    # row check
    for i in range(n):
        s1 = 0
        for j in range(n):
            s1 += matrix[i][j]
        if s1 != ans:
            flag = 1
            break
    # col check
    for i in range(n):
        s1 = 0
        for j in range(n):
            s1 += matrix[j][i]
        if s1 != ans:
            flag = 1
            break
    # diagonal check
    s1 = 0
    for i in range(n):
        s1 += matrix[i][i]
    if s1 != ans:
        flag = 1
    s1 = 0
    for i in range(n):
        s1 += matrix[i][n-1-i]
    if s1 != ans:
        flag = 1
    if flag == 1:
        print(-1)
    else:
        if rem <= 0:
            print(-1)
        else:
            print(rem)
