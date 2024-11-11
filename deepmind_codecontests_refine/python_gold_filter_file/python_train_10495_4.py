import sys
sys.setrecursionlimit(180000)

def dfs(i,j):
    for m in move:
        ni = i + m[0]
        nj = j + m[1]
        if ni < 0 or ni >= H or nj < 0 or nj >= W:
            continue
        if ch[ni][nj]:
            continue
        if X[i][j] == X[ni][nj]:
            continue
            
        ch[ni][nj] = 1
        K[(ni+nj)%2] += 1
        dfs(ni, nj)
        
H, W = map(int, input().split())
X = [[[0, 1][a=="#"] for a in input()] for i in range(H)]
ch = [[0] * W for _ in range(H)]
    
move = [[0,1], [0,-1], [1,0], [-1,0]]

K = [0, 0]
ans = 0
for i in range(H):
    for j in range(W):
        if ch[i][j] > 0:
            continue
        ch[i][j] = 1
        K = [0, 0]
        K[(i+j)%2] = 1
        dfs(i, j)
        ans += K[0] * K[1]
        
print(ans)

