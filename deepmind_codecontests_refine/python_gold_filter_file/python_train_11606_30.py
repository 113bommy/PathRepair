n=int(input())
t=[[1]*n]*n
for i in range(1,n):
    for j in range(1,n):
        t[i][j]=t[i-1][j]+t[i][j-1]
print(t[n-1][n-1])
