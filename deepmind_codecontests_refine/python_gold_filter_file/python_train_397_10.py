from collections import deque

INF = float("inf")

H, W, K = map(int, input().split())
A = [list(input()) for _ in range(H)]

Si, Sj = (0, 0)
for i, a in enumerate(A):
    if "S" in a:
        Si, Sj = (i, a.index("S"))
        break

dist = [[INF] * W for _ in range(H)]
dist[Si][Sj] = 0


ans = INF

Q = deque([(Si, Sj)])
while Q:
    i, j = Q.popleft()

    ans = min(
        ans,
        1 + (i + K - 1) // K,
        1 + (j + K - 1) // K,
        1 + (H - 1 - i + K - 1) // K,
        1 + (W - 1 - j + K - 1) // K
    )

    if dist[i][j] == K:
        continue

    distance = dist[i][j] + 1

    for di, dj in ((1, 0), (0, 1), (-1, 0), (0, -1)):
        ni, nj = i + di, j + dj

        if not (0 <= ni < H and 0 <= nj < W and A[ni][nj] == "."):
            continue

        A[ni][nj] = "#"

        if dist[ni][nj] > distance:
            dist[ni][nj] = distance
            Q.append((ni, nj))

print(ans)
