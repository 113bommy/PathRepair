N = int(input())
grid=[[v for v in input()] for _ in range(N)]

ans=0
for a in range(N):
    new_grid=[]
    new_grid.extend(grid[a:])
    new_grid.extend(grid[:a])

    flag=True
    for i in range(N):
        for j in range(N):
            if new_grid[i][j]==new_grid[j][i]:
                continue
            else:
                flag=False
                break
    if flag:
        ans+=1
print(ans*N)
