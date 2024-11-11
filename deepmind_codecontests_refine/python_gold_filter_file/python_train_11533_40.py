from collections import deque

h, w = map(int, input().split())
i0, j0 = map(lambda x: int(x) - 1, input().split())
i1, j1 = map(lambda x: int(x) - 1, input().split())
S = [input() for i in range(h)]
D = [[-1] * w for i in range(h)]
Q = deque([(i0, j0, 0)])
while Q:
    i, j, cnt = Q.popleft()
    if D[i][j] != -1:
        continue
    D[i][j] = cnt
    for di in range(-2, 3):
        for dj in range(-2, 3):
            if 0 <= i + di < h and 0 <= j + \
                    dj < w and S[i + di][j + dj] == "." and D[i + di][j + dj] == -1:
                if abs(di) + abs(dj) == 1:
                    Q.appendleft((i + di, j + dj, cnt))
                else:
                    Q.append((i + di, j + dj, cnt + 1))
print(D[i1][j1])
