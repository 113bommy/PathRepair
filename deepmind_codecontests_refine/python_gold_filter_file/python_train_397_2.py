import itertools, math, collections, sys
input = sys.stdin.readline
H, W, K = [int(_) for _ in input().split()]
A = [input() for _ in range(H)]
for h in range(H):
    if 'S' in A[h]:
        w = A[h].index('S')
        break
visited = [[False] * W for _ in range(H)]
ans = min([h, H - 1 - h, w, W - 1 - w])
res = K - 1
Q = collections.deque([[h - 1, w, res], [h + 1, w, res], [h, w - 1, res],
                       [h, w + 1, res]])
while Q:
    h, w, res = Q.popleft()
    if 0 <= h < H and 0 <= w < W and A[h][w] == '.' and not visited[h][w]:
        visited[h][w] = True
        ans = min([ans, h, H - 1 - h, w, W - 1 - w])
        if res:
            res -= 1
            Q += [[h - 1, w, res], [h + 1, w, res], [h, w - 1, res],
                  [h, w + 1, res]]
print(1 + math.ceil(ans / K))
