from collections import defaultdict

t = int(input())
for _ in range(t):
    n = int(input())
    grid = []
    for i in range(n):
        grid.append([i for i in input()])
    if grid[0][1] == grid[1][0]:
        ans = []
        if grid[0][1] == '0':
            if grid[n-1][n-2] == '0':
                ans.append([n, n-1])
            if grid[n-2][n-1] == '0':
                ans.append(([n-1, n]))
        if grid[0][1] == '1':
            if grid[n-1][n-2] == '1':
                ans.append([n, n-1])
            if grid[n-2][n-1] == '1':
                ans.append(([n-1, n]))
    else:
        ans = []
        if grid[n-1][n-2] == grid[n-2][n-1]:
            x = grid[n-1][n-2]
            if grid[0][1] == x:
                ans.append([1, 2])
            if grid[1][0] == x:
                ans.append([2, 1])
        else:
            if grid[0][1] == '1':
                ans.append([1, 2])
            if grid[1][0] == '1':
                ans.append([2, 1])
            if grid[n-1][n-2] == '0':
                ans.append([n, n-1])
            if grid[n-2][n-1] == '0':
                ans.append(([n - 1, n]))
    print(len(ans))
    for i in ans:
        print(*i)