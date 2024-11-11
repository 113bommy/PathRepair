n,m,l = map(int,input().split())
a = [list(map(int,input().split())) for i in range(n)]
b = [list(map(int,input().split())) for i in range(m)]
for i in range(n):
    for j in range(l):
        sum = 0
        for k in range(m):
            sum += a[i][k]*b[k][j]
        if j==l-1:print(sum)
        else:print(sum,end=" ")

