import sys

n = int(input())

if n == 1:
    print(1)
    sys.exit(0)

magic_square = []
for _ in range(n):
    magic_square.append(list(map(int, input().split())))

row_sums, col_sums = [], []
da, db = 0, 0
ret = 0

def cal():
    global da, db
    for row in magic_square:
        row_sums.append(sum(row))
    for i in range(n):
        acc = 0
        for j in range(n):
            acc += magic_square[j][i]
        col_sums.append(acc)
        da += magic_square[i][i]
        db += magic_square[-i-1][i] 

cal()

if len(set(row_sums)) > 2 or len(set(col_sums)) > 2:
    print(-1)
else:
    x, y = 0, 0
    difx, dify = row_sums[1] - row_sums[0], col_sums[1] - col_sums[0]
    for i in range(1, n):
        if row_sums[i] < row_sums[i-1]:
            x, difx = i, row_sums[i-1] - row_sums[i]
        if col_sums[i] < col_sums[i-1]:
            y, dify = i, col_sums[i-1] - col_sums[i]
    if difx != dify:
        print(-1)
    else:
        magic_square[x][y] = difx
        row_sums, col_sums = [], []
        da, db = 0, 0
        cal()
        row_sums.append(da)
        col_sums.append(db)
        if len(set(row_sums)) > 1 or len(set(col_sums)) > 1:
            print(-1)
        else:
            print(difx)
