def neighbors(n,m, x,y, grid):
    if x+1<n and grid[x+1][y] == 'P':
        return True
    if x-1 >= 0 and grid[x-1][y] == 'P':
        return True
    if y+1 <m and grid[x][y+1] == 'P':
        return True
    if y-1 >= 0 and grid[x][y-1] == 'P':
        return True
    return False

n, m = map(int, input().split())
grid = []
for i in range(n):
    grid.append(list(input()))
score = 0
for i in range(n):
    for j in range(m):
        if grid[i][j] == 'W' and neighbors(n,m,i,j,grid):
            score+=1
print(score)