from collections import deque


h, w = map(int,input().split())
ch, cw = map(lambda x: int(x) - 1, input().split())
dh, dw = map(lambda x: int(x) - 1, input().split())

G = []
for i in range(h):
    G.append(list(input()))

queue = deque([(ch, cw)])
S = [[float("inf")]*w for _ in range(h)]
S[ch][cw] = 0

while queue:
    y, x = queue.popleft()
    dx_dy = ((1,0),(0,1),(-1,0),(0,-1))
    ans = S[y][x]

    if (y, x) == (dh, dw):
            S[y][x] = ans
            break

    for j, i in dx_dy:
        if 0 <= x+i < w and 0 <= y+j < h and S[y+j][x+i] > ans and G[y+j][x+i] == ".":
            queue.appendleft((y+j, x+i))
            S[y+j][x+i] = ans
            

    ans += 1
    for i in range(-2, 3):
        for j in range(-2, 3):
            if 0 <= x+i < w and 0 <= y+j < h and S[y+j][x+i] > ans and G[y+j][x+i] == ".":
                S[y+j][x+i] = ans
                queue.append((y+j, x+i))


if S[dh][dw] == float("inf"):
    print(-1)
else:
    print(S[dh][dw])
