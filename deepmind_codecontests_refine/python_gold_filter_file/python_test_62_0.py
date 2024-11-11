# E. Staircases

from sys import stdin, stdout
input = stdin.readline
print = stdout.write

n, m, q = list(map(int, input().split()))
 
matrix = [[[0, 0] for i in range(m)] for j in range(n)]
free = [[True for i in range(m)] for j in range(n)]
 
ans = 0
 
for i in range(n):
    for j in range(m):
        if i > 0: matrix[i][j][1] += matrix[i-1][j][0]
        if j > 0: matrix[i][j][0] += matrix[i][j-1][1]
        
        matrix[i][j][0] += 1
        matrix[i][j][1] += 1
        
        ans += matrix[i][j][0]+matrix[i][j][1]-1
        
for _ in range(q):
    x, y = list(map(int, input().split()))
 
    x -= 1
    y -= 1
    
    count_right = 0
    
    act_x = x
    act_y = y+1
    
    right = True
    
    while act_x < n and act_y < m and free[act_x][act_y]:
        count_right += 1
        
        if right:
            act_x += 1
        else: act_y += 1
        
        right = not right
        
    count_down = 0
    
    act_x = x+1
    act_y = y
    
    right = False
    
    while act_x < n and act_y < m and free[act_x][act_y]:
        count_down += 1
        
        if right:
            act_x += 1
        else: act_y += 1
        
        right = not right
        
    count_left = 0
    
    act_x = x
    act_y = y-1
    
    left = True
    
    while act_x >= 0 and act_y >= 0 and free[act_x][act_y]:
        count_left += 1
        
        if left:
            act_x -= 1
        else: act_y -= 1
        
        left = not left
        
    count_up = 0
    
    act_x = x-1
    act_y = y
    
    left = False
    
    while act_x >= 0 and act_y >= 0 and free[act_x][act_y]:
        count_up += 1
        
        if left:
            act_x -= 1
        else: act_y -= 1
        
        left = not left
        
    count_stairs = 0
    
    count_stairs += (count_up+1)*(count_right+1)
    count_stairs += (count_down+1)*(count_left+1)
        
    count_stairs -= 1
    
    if free[x][y]:
        ans -= count_stairs
    else:
        ans += count_stairs
        
    free[x][y] = not free[x][y]
        
    print(str(ans)+"\n")