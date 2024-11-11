H, W, K = map(int, input().split())
S = [list(map(int, input())) for _ in range(H)]


def add(j):
    for i in range(g):
        now[i] += c[i][j]
    for i in range(g):
        if now[i] > K:
            return False
    return True


ans = 10**30
for i in range(2 ** (H-1)):
    g = 0
    id = [-1]*H
    for j in range(H):  # このループが一番のポイント
        id[j] = g
        if (i >> j & 1):  # 順に右にシフトさせ最下位bitのチェックを行う
            g += 1
    g += 1

    c = [[0] * W for _ in range(H)]
    for i in range(H):
        for j in range(W):
            c[id[i]][j] += S[i][j]

    num = g-1
    now = [0]*g
    for j in range(W):
        if not add(j):
            num += 1
            now = [0]*g
            if not add(j):
                num = 10**30
                continue

    ans = min(ans, num)

print(ans)
