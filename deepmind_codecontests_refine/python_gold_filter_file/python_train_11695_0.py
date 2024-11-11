n=int(input())
mat=[]
for i in range(n):
    mat.append([int(i) for i in input().split()])
sm=0
if n<=3:
    for i in range(n):
        for j in range(n):
            sm+=mat[i][j]
    print(sm)
    exit()
sm=0 
for i in range(n):
    sm+=mat[i][i]
    sm+=mat[i][n-1-i]
for i in range(n):
    sm+=mat[i][n//2]
for i in range(n):
    sm+=mat[n//2][i]
sm=sm-3*mat[n//2][n//2]
print(sm)