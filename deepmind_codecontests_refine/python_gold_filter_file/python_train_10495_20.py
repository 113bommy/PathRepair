import sys
sys.setrecursionlimit(10**9)
H, W = map(int, input().split())
S = [list(input()) for _ in range(H)]

cntblack, cntwhite = 0, 0
visited = [[False] * W for _ in range(H)]

def count(h, w):
    global cntblack, cntwhite
    if visited[h][w]: return
    visited[h][w] = True
    if S[h][w] == ".": cntwhite += 1
    else: cntblack += 1
    for ny, nx in ((1,0),(0,1),(-1,0),(0,-1)):
        ny += h
        nx += w
        if not (0 <= ny < H and 0 <= nx < W): continue
        if S[ny][nx] == S[h][w]: continue
        count(ny, nx)


ans = 0
for h in range(H):
    for w in range(W):
        cntblack, cntwhite = 0, 0
        count(h, w)
        ans += cntblack * cntwhite

print(ans)
