n,q = map(int, input().split())
maze = [[False] * n, [False] * n]
numBlocks = 0
for _ in range(q):
    x,y = map(int, input().split())
    x -= 1
    y -= 1
#    print(x,y)
    maze[x][y] = not maze[x][y]
#    print(maze)
    for dy in range(-1,2):
        if 0 <= y + dy < n and maze[1-x][y + dy]:
            if maze[x][y]:
                numBlocks += 1
            else:
                numBlocks -= 1
#    print(numBlocks)
    if numBlocks == 0:
        print('YES')
    else:
        print('NO')

