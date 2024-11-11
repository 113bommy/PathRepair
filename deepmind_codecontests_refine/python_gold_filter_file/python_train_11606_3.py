n=int(input())
table=[[1]*n]*n
for i in range(1,n):
    for j in range(1,n):
        table[i][j]=table[i][j-1]+table[i-1][j]
print(table[n-1][n-1])