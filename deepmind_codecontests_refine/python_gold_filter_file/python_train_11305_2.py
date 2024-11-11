import sys
import math
n,k = map(int, input().split())
ans = [[0 for i in range(n)] for i in range(n)]
row = 0;
col = 0;
scol = 0;
while(row < n):
    col = scol
    while(col < n):
        if(col == row and k > 0):
            ans[row][col] = 1
            k  -= 1
        elif k > 0:
            if k >= 2:
                ans[row][col] = 1
                ans[col][row] = 1
                k -= 2
        col += 1
     
    row += 1
    scol += 1
if k == 0:
    for i in range(n):
        for j in range(n):
            print(ans[i][j], end = " ")
        print()
else:
    print(-1)
