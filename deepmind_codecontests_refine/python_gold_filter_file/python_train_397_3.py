from collections import deque


h, w, k = map(int, input().split())
a = [input() for i in range(h)]
INF= 10**9

for i in range(h):
    for j in range(w):
        if a[i][j] == "S":
            si, sj = i, j
            break

cnt = [[INF] * w for i in range(h)]
cnt[si][sj] = 0
q = deque([(si, sj, 0)])
while q:
    pi, pj, cost = q.popleft()
    for nxi, nxj in [(pi+1, pj), (pi, pj+1), (pi-1, pj), (pi, pj-1)]:
        if not (0 <= nxi < h and 0 <= nxj < w):
            continue
        if a[nxi][nxj] == "." and cost + 1 < cnt[nxi][nxj] and cost + 1 <= k:
            cnt[nxi][nxj] = cost + 1
            q.append((nxi, nxj, cost + 1))

ans = 10**9
for i in range(h):
    for j in range(w):
        if cnt[i][j] <= k:
            ans = min(ans, -((-i)//k), -((-(h-i-1))//k), -((-j)//k), -((-(w-j-1))//k))

print(ans+1)