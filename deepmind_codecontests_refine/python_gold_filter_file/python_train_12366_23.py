H, W, K = map(int, input().split())
S = []
for _ in range(H):
    S.append([c for c in input()])

ans = float('inf')
for div in range(2 ** (H - 1)):
    g = 0
    ids = [0] * H
    for i in range(H):
        ids[i] = g
        if div >> i & 1:
            g += 1
    g += 1

    c = [[0 for _ in range(1005)] for _ in range(10)]
    for i in range(H):
        for j in range(W):
            c[ids[i]][j] += int(S[i][j])

    num = g - 1
    now = [0] * g
    def add(j):
        for i in range(g):
            now[i] += c[i][j]
            if now[i] > K:
                return False
        return True

    for j in range(W):
        if not add(j):
            num += 1
            now = [0] * g
            if not add(j):
                num = float('inf')
                break

    ans = min(ans, num)
print(ans)
