dhw = [(1,0),(0,-1),(0,1),(-1,0),
( 2,-2),( 2,-1),( 2, 0),( 2, 1),( 2, 2),
( 1,-2),( 1,-1),        ( 1, 1),( 1, 2),
( 0,-2),                        ( 0, 2),
(-1,-2),(-1,-1),        (-1, 1),(-1, 2),
(-2,-2),(-2,-1),(-2, 0),(-2, 1),(-2, 2)]

H, W = map(int, input().split())
sh, sw = map(lambda x:int(x)-1, input().split())
eh, ew = map(lambda x:int(x)-1, input().split())
S = [input() for _ in range(H)]

dst = [[-1]*W for _ in range(H)]

from collections import deque
dq = deque([(sh, sw, 0)])
while dq:
    h, w, d = dq.popleft()
    if 0 <= h < H and 0 <= w < W and dst[h][w] < 0 and S[h][w] != '#':
        dst[h][w] = d
    else:
        continue
    for i in range(4): dq.appendleft((h + dhw[i][0], w + dhw[i][1], d))
    for i in range(4, 24): dq.append((h + dhw[i][0], w + dhw[i][1], d+1))

print(dst[eh][ew])
