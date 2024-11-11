row, col = [int(i) for i in input().split()]
'''
   Given a grid of cells containing walls and no walls, and that placing a bomb 
   anywhere on the grid clears all cells in the corresponding row and column, 
   the program returns if plaicng a bomb at any given point can clear all the 
   walls in the grid
'''
#initilaizing variables
grid = []
total_walls = 0
G = [0]*row
V = [0]*col
check = False

#getting input from the user and counting number of walls in each row 
for i in range(row):
    a = input()
    total_walls += a.count('*')
    grid.append(a)
    G[i] = a.count('*')
    
#creating columnwise grid
X = ['']
X = X*col
for i in grid:
    for j in range(col):
        X[j]+=i[j]

#counting number of walls in each column
for j in range(col):
    V[j] = X[j].count('*')

#couting number of walls at each point in the grid
for i in range(row):
    for j in range(col):
        if grid[i][j] == '.':
            cur = G[i] + V[j]
        else:
            cur = G[i] + V[j] - 1
        if cur == total_walls:
            print("YES")
            print(i+1, j+1)
            check = True
            break
    if check == True:
        break
if check == False:
    print("NO")
    