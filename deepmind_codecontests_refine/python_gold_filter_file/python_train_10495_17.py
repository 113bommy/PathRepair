import sys
sys.setrecursionlimit(10**9)

h,w = map(int, input().split())
board = [[int(j=="#") for j in input()] for i in range(h)]
dxdy = [(0,1), (0,-1), (1,0), (-1,0)]

def dfs(i, j, k, prev):
    if used[i][j] or board[i][j] == prev:
        return
    used[i][j] = 1
    k[board[i][j]] += 1
    for dx, dy in dxdy:
        nx, ny = i+dx, j+dy
        if 0 <= nx < h and 0 <= ny < w and not used[nx][ny] and board[nx][ny] != board[i][j]:
            dfs(nx,ny,k,board[i][j])

used = [[0]*w for i in range(h)]
ans = 0
for i in range(h):
    for j in range(w):
        if used[i][j]:
            continue
        k = [0]*2
        dfs(i,j,k, -1)
        ans += k[0]*k[1]
print(ans)
