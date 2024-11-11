from collections import deque
import sys
input = sys.stdin.readline

H, W = map(int, input().split())
CH, CW = map(lambda x: int(x) - 1, input().split())
DH, DW = map(lambda x: int(x) - 1, input().split())
S = [input().rstrip() for _ in range(H)]
v = [[False] * W for _ in range(H)]
dq = deque([(0, CH, CW)])
while dq:
    d, h, w = dq.popleft()
    if (h, w) == (DH, DW):
        print(d)
        exit()
    if v[h][w]:
        continue
    v[h][w] = True
    for mh, mw in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
        nh, nw = mh + h, mw + w
        if 0 <= nh < H and 0 <= nw < W and S[nh][nw] == '.':
            dq.appendleft([d, nh, nw])
    for mh in range(-2, 3):
        for mw in range(-2, 3):
            if mh == mw == 0:
                continue
            nh, nw = mh + h, mw + w
            if 0 <= nh < H and 0 <= nw < W and S[nh][nw] == '.' and not v[nh][nw]:
                dq.append([d + 1, nh, nw])
print(-1)