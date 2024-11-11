n = int(input())
lst= [[None] * 10] *10 
if n == 1:
    print('1')
else:
    for i in range(n):
        lst[0][0] = 1
        lst[i][0] = 1
        lst[0][i] = 1
    for i in range(1, n):
        for j in range(1,n):
            lst[i][j] = lst[i-1][j] + lst[i][j-1]
    print(lst[n-1][n-1])
