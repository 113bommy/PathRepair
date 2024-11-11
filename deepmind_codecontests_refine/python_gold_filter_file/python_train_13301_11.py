import sys
from pprint import pprint

R,C,K=map(int,input().split())

grid=[[0]*C for _ in range(R+1)]
for _ in range(K):
    r,c,v=map(int,input().split())
    grid[r][c-1]=v

for i in range(1,R+1):
    cell=[0]*4
    for j in range(C):
        cell[0]=max(cell[0],grid[i-1][j])
        for k in range(2,-1,-1):
            cell[k+1]=max(cell[k+1],cell[k]+grid[i][j])
        grid[i][j]=max(cell)

print(grid[-1][-1])
