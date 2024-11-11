import collections, itertools

h, w = map(int, input().split())
ch, cw = tuple(int(s) - 1 for s in input().split())
dh, dw = tuple(int(s) - 1 for s in input().split())
s = [input() for _ in range(h)]

q = collections.deque()
q.append((ch, cw, 0))
score = [[float('inf')] * w for _ in range(h)]
score[ch][cw] = 0
while q:
    x, y, p = q.popleft()

    for dx, dy in ((0, 1), (1, 0), (0, -1), (-1, 0)):
        nx, ny = x + dx, y + dy
        if 0 <= nx < h and 0 <= ny < w and s[nx][ny] == '.' and p < score[nx][ny]:
            score[nx][ny] = p
            q.appendleft((nx, ny, p))
    
    for dx, dy in itertools.product(range(-2, 3), repeat=2):
        nx, ny = x + dx, y + dy
        if 0 <= nx < h and 0 <= ny < w and s[nx][ny] == '.' and p + 1 < score[nx][ny]:
            score[nx][ny] = p + 1
            q.append((nx, ny, p + 1))

if score[dh][dw] == float('inf'):
    print(-1)
else:
    print(score[dh][dw])