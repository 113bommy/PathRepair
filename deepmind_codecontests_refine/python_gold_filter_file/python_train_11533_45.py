from collections import deque
import sys
sys.setrecursionlimit(10**6)

readline = sys.stdin.readline
H, W = map(int, input().split())
Ch, Cw = map(lambda x: int(x) - 1, input().split())
Dh, Dw = map(lambda x: int(x) - 1, input().split())
S = [readline().rstrip() for _ in range(H)]

visited = [[False] * W for _ in range(H)]
dq = deque([(0, Ch, Cw)])

while dq:
    d, i, j = dq.popleft()
    if (i, j) == (Dh, Dw):
        print(d)
        exit()
    if visited[i][j]:
        continue
    visited[i][j] = True
    for di, dj in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
        ni, nj = i + di, j + dj
        if 0 <= ni < H and 0 <= nj < W and S[ni][nj] == '.':
            dq.appendleft((d, ni, nj))
    for di in range(-2, 3):
        for dj in range(-2, 3):
            if di == dj == 0:
                continue
            ni, nj = i + di, j + dj
            if 0 <= ni < H and 0 <= nj < W and S[ni][nj] == '.' and not visited[ni][nj]:
                dq.append((d + 1, ni, nj))
print(-1)
