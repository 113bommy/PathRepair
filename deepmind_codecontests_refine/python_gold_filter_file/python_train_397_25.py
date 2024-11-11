from collections import deque

H,W,K = map(int,input().split())
src = [input() for i in range(H)]
sx = sy = None
for i,row in enumerate(src):
    if 'S' in row:
        sy = i
        sx = row.index('S')

dxy = [(0,1),(1,0),(0,-1),(-1,0)]
visited = [[0]*W for i in range(H)]
visited[sy][sx] = 1
q = deque([(0,sx,sy)])
mindist = H+W
while q:
    d,x,y = q.popleft()
    if d > K: break
    dist = min(x, W-x-1, y, H-y-1)
    mindist = min(dist, mindist)
    for dx,dy in dxy:
        nx,ny = x+dx,y+dy
        if not 0 <= nx < W: continue
        if not 0 <= ny < H: continue
        if src[ny][nx] == '#': continue
        if visited[ny][nx]: continue
        q.append((d+1,nx,ny))
        visited[ny][nx] = 1

ans = -(-mindist//K) + 1
print(ans)