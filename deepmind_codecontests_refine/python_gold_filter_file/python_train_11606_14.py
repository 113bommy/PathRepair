n=int(input())
l=[[1]*n]*n
for i in range(1,n):
    for j in range(1,n):
        l[i][j]=l[i-1][j]+l[i][j-1]
print(l[n-1][n-1])