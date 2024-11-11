import sys
sys.setrecursionlimit(300000)

H, W = map(int, input().split())
S = [input() for y in range(H)]
visited = [[False] * W for y in range(H)]

def color(y, x):
    if y < 0 or H <= y or x < 0 or W <= x or visited[y][x]:
        return "@"
    else:
        return S[y][x]


def dfs(y, x):
    b = 0
    w = 0
    nxt = "n"
    if color(y, x) == ".":
        w = 1
        nxt = "#"
    elif color(y, x) == "#":
        b = 1
        nxt = "."
    
    visited[y][x] = True
    if color(y - 1, x) == nxt:
        _b, _w = dfs(y - 1, x)
        b += _b
        w += _w
    if color(y + 1, x) == nxt:
        _b, _w = dfs(y + 1, x)
        b += _b
        w += _w
    if color(y, x - 1) == nxt:
        _b, _w = dfs(y, x - 1)
        b += _b
        w += _w
    if color(y, x + 1) == nxt:
        _b, _w = dfs(y, x + 1)
        b += _b
        w += _w

    return (b, w)

    
ans = 0
for y in range(H):
    for x in range(W):
        b, w = dfs(y, x)
        ans += b * w

print(ans)