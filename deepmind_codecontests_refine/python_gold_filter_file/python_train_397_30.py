H, W, K = map(int, input().split())
items = []

start = []
diff = float("inf")
p = []
prev = [[False] * W for _ in range(H)]
for i in range(H):
    items.append(list(input()))
    for j in range(W):
        s = items[i][j]
        if s == "S":
            start = [i, j]
            diff = min(diff, min(i, H - 1 - i, min(j, W - 1 - j)))
            p = [i, j]
            prev[i][j] = True

from collections import deque

que = deque([])

dx = [-1, 0, 0, 1]
dy = [0, 1, -1, 0]

for i in range(4):
    x = dx[i]
    y = dy[i]
    if 0 <= start[0] + y <= H - 1 and 0 <= start[1] + x <= W - 1:
        tmp = items[start[0] + y][start[1] + x]
        if tmp == ".":
            que.append((start[0] + y, start[1] + x))
            prev[start[0] + y][start[1] + x] = True
k = K
while len(que) != 0:
    q = que.popleft()
    a = q[0]
    b = q[1]
    if abs(start[0] - a) + abs(start[1] - b) > K:
        continue
    c = min(min(a, H - 1 - a), min(b, W - 1 - b))
    if c < diff:
        diff = c
        p = (a, b)

    for i in range(4):
        x = dx[i]
        y = dy[i]
        if 0 <= a + y <= H - 1 and 0 <= b + x <= W - 1:
            if prev[a + y][b + x]:
                continue
            tmp = items[a + y][b + x]
            if tmp == ".":
                que.append((a + y, b + x))
                prev[a + y][b + x] = True

ans = 1
if diff == 0:
    print(ans)
else:
    print(ans + (K - 1 + diff) // K)
