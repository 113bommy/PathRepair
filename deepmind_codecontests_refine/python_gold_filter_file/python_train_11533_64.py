from collections import deque
from itertools import product
h, w = list(map(int,input().split()))
sy, sx = list(map(int,input().split()))
gy, gx = list(map(int,input().split()))
sx, sy, gx, gy = sx-1, sy-1, gx-1, gy-1
 
G = [list(input()) for _ in range(h)]
D = [[10**6]*w for _ in range(h)]
D[sy][sx] = 0
Q = deque([(sy, sx)])
while Q:
    y, x = Q.pop()
    for dy, dx in product(range(-2, 3), repeat=2):
        ny, nx = y+dy, x+dx
        if dx==dy==0:
            G[y][x] = '#'
            continue
        elif ny<0 or h<=ny or nx<0 or w<=nx:
            continue
        elif G[ny][nx] == '#':
            continue
        elif abs(dy)+abs(dx)<=1:
            G[ny][nx] = '#'
            D[ny][nx] = D[y][x]
            Q.append((ny, nx))
        elif D[ny][nx] == 10**6:
            D[ny][nx] = D[y][x]+1
            Q.appendleft((ny, nx))
            
if D[gy][gx] == 10**6:
    print(-1)
else:
    print(D[gy][gx])
