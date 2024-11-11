from itertools import permutations
N, C = map(int, input().split())
D = [list(map(int, input().split())) for i in range(C)]  # 違和感
G = [list(map(int, input().split())) for i in range(N)]  # 初期盤面
X = [[0] * C for i in range(3)]  # modが0~2 × 各色への変更 の違和感の和

for c in range(C):  # 色
    tmp = [0] * 3  # 各modの違和感の和
    for i in range(N):
        for j in range(N):
            tmp[(i + j) % 3] += D[G[i][j] - 1][c]
    for t in range(3):
        X[t][c] = tmp[t]

ans = float('inf')
for c1, c2, c3 in permutations(range(C), 3):
    ans = min(ans, X[0][c1] + X[1][c2] + X[2][c3])

print(ans)
