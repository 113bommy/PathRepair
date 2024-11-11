h,w = map(int, input().split())
s = []
for i in range(h):
    s.append(input())
import sys
sys.setrecursionlimit(200000)
dy = [0,0,1,-1]
dx = [1,-1,0,0]
def dfs(y,x):
    global check
    global was
    was[y][x] = 1
    if s[y][x] == "#":
        check[0] += 1
    else:
        check[1] += 1
    for k in range(4):
        nx = x + dx[k]
        ny = y + dy[k]
        if nx >= 0 and ny >= 0 and nx < w and ny < h and s[ny][nx] != s[y][x] and not was[ny][nx]:
            dfs(ny,nx)
ans = 0
was = [[0 for i in range(w)] for j in range(h)]
for i in range(w):
    for j in range(h):
        if not was[j][i]:
            check = [0,0]
            dfs(j,i)
            ans += check[0] * check[1]
print(ans)