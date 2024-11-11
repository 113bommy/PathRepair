import sys

sys.setrecursionlimit(1000*1000)

H, W = map(int, input().split(" "))
map_info = [input() for i in range(H)]

visit = [[False for j in range(W)] for i in range(H)]
ans = 0


def search(i, j, want_color):
    if i < 0 or i >= H:
        return
    if j < 0 or j >= W:
        return
    if visit[i][j]:
        return
    this_color = map_info[i][j]
    if want_color != this_color:
        return

    global white
    global black

    visit[i][j] = True
    if this_color == '.':
        white += 1
        next_color = '#'
    else:
        black += 1
        next_color = '.'
    search(i, j+1, next_color)
    search(i, j-1, next_color)
    search(i+1, j, next_color)
    search(i-1, j, next_color)


for i in range(H):
    for j in range(W):
        white = 0
        black = 0
        search(i, j, map_info[i][j])
        ans += black * white
print(ans)
