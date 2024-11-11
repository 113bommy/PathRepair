from collections import deque

h, w = map(int, input().split())
ch, cw = map(lambda x: int(x)-1, input().split())
dh, dw = map(lambda x: int(x)-1, input().split())
maze = [input() for _ in range(h)]

INF = 10**12
path = [[INF] * w for _ in range(h)] #ここに各マスの移動コストを記録する

walk = [(1,0), (0,1), (-1,0), (0,-1)] #ワープしない移動
warp = [(i,j) for i in range(-2,3) for j in range(-2,3) if (i,j) not in [(0,0)] + walk] #ワープするときの移動

q = deque()
path[ch][cw] = 0
q.append((ch, cw, 0))

while q:
    x, y, s = q.popleft()
    for dx, dy in walk:
        nx = x + dx
        ny = y + dy
        if 0 <= nx < h and 0 <= ny < w and maze[nx][ny] != "#" and path[nx][ny] > s:
            path[nx][ny] = s
            q.appendleft((nx, ny, s))
    for dx, dy in warp:
        nx = x + dx
        ny = y + dy
        if 0 <= nx < h and 0 <= ny < w and maze[nx][ny] != "#" and path[nx][ny] > s+1:
            path[nx][ny] = s+1
            q.append((nx, ny, s+1))

ans = path[dh][dw] if path[dh][dw] < INF else -1
print(ans)