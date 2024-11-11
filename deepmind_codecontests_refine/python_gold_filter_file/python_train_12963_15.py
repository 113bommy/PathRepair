n = int(input())
grid = []
for i in range(n):
    tokens = input().split()
    grid.append([tokens[0], int(tokens[1]), int(tokens[2])])
ans = 0
for i in range(366):
    males, females = 0, 0
    for j in range(n):
        if grid[j][1] - 1 <= i <= grid[j][2] - 1:
            if grid[j][0] == 'M':
                males += 1
            else:
                females += 1
    x = 2 * min(males, females)
    if x > ans:
        ans = x
print(ans)