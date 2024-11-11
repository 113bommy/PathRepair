def dfs(x, y, num):
    global visit
    visit[x][y] = num
    for k in range(4):
        x1 = x + dx[k]
        y1 = y + dy[k]
        if 0 <= x1 < n and 0 <= y1 < m:
            if dots[x][y] == dots[x1][y1]:
                if visit[x1][y1] == 0:
                    dfs(x1, y1, num + 1)
                if abs(visit[x][y] - visit[x1][y1]) >= 3:
                    print("Yes")
                    quit()


n, m = map(int, input().split())
dots = [list(input()) for i in range(n)]
visit = [[0] * m for i in range(n)]
dx = [0, -1, 0 ,1]
dy = [1, 0, -1, 0]
for i in range(n):
    for j in range(m):
        if visit[i][j] == 0:
            dfs(i, j, 1)
print("No")

