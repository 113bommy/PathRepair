from collections import deque


h, w = map(int, input().split())
Ch, Cw = map(lambda x: int(x)-1, input().split())
Dh, Dw = map(lambda x: int(x)-1, input().split())
dy, dx = (-1, 0, 1, 0), (0, -1, 0, 1)
maze = [[float('inf') if x == '.' else -float('inf') for x in input()] for _ in range(h)]
maze[Ch][Cw] = 0
que = deque()
que.append((0, Ch, Cw))
while que:
    c, y, x = que.popleft()
    
    if c > maze[y][x]:
        continue
    
    if y == Dh and x == Dw:
        break
    
    for i in range(4):
        y2, x2 = y + dy[i], x + dx[i]
        if 0 <= y2 < h and 0 <= x2 < w and c < maze[y2][x2]:
            maze[y2][x2] = c
            que.appendleft((c, y2, x2))
            
    for i in range(-2, 3):
        for j in range(-2, 3):
            y3, x3, c2 = y + i, x + j, c+1
            if 0 <= y3 < h and 0 <= x3 < w and c2 < maze[y3][x3]:
                maze[y3][x3] = c2
                que.append((c2, y3, x3))

ans = maze[Dh][Dw]
if ans == float('inf'):
    print(-1)
else:
    print(ans)