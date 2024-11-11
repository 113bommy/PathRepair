import sys
readline = sys.stdin.readline

H, W = map(int, readline().split())
G = [[0]*W for _ in range(H)]
L1 = [[0]*1000 for _ in range(W+H-1)]
geta1 = W-1
L2 = [[0]*1000 for _ in range(W+H-1)]
for i in range(H):
    S = [1 if s == '#' else 0 for s in readline().strip()]
    for j in range(W):
        G[i][j] = S[j]
        if S[j]:
            L1[i-j+geta1][i] = 1
            L2[i+j][i] = 1
for sub in range(W+H-1):
    for i in range(630):
        L1[sub][i] += L1[sub][i-1]
        L2[sub][i] += L2[sub][i-1]

res = 0
for su in range(2*max(H, W)+1):
    for w in range(max(0, su-H+1), min(W, su+1)):
        h = su-w
        if not G[h][w]:
            continue
        for k in range(1, min(h+1, W-w)):
            if not G[h-k][w+k]:
                continue
            idx1 = h+w-2*k
            if 0 <= idx1 < H+W-1:
                res += L2[idx1][h-k-1] - L2[idx1][h-2*k]
            idx2 = h+w+2*k
            if 0 <= idx2 < H+W-1:
                res += L2[idx2][h+k-1] - L2[idx2][h]

for mi in range(1-W, H):
    for w in range(max(0, -mi), min(W, H-mi)):
        h = mi + w
        if not G[h][w]:
            continue
        for k in range(1, min(H-h, W-w)):
            if not G[h+k][w+k]:
                continue
            idx1 = h-w-2*k + geta1
            if 0 <= idx1 < H+W-1:
                res += L1[idx1][h] - L1[idx1][h-k-1]
            idx2 = h-w+2*k + geta1
            if 0 <= idx2 < H+W-1:
                res += L1[idx2][h+2*k] - L1[idx2][h+k-1]

print(res)