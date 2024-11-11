import sys
def input(): return sys.stdin.readline().rstrip()
sys.setrecursionlimit(10 ** 7)
INF = 1001001001

H, W, K = map(int, input().split())
S = [list(map(int, list(input()))) for _ in range(H)]
# print(S)

ans = INF
for b in range(1<<(H-1)):
    g = 0
    idx = [0]*H
    for i in range(H-1):
        if b>>i&1:
            g += 1
        idx[i+1] = g
    g += 1
    cnt = [[0]*W for _ in range(g)]
    for i in range(H):
        for j in range(W):
            cnt[idx[i]][j] += S[i][j]
    num = g-1
    now = [0]*g

    def add(j):
        global now
        for i in range(g):
            now[i] += cnt[i][j]
            if now[i] > K:
                return False
        return True

    for j in range(W):
        if add(j)==False:
            num += 1
            now = [0]*g
            if add(j)==False:
                num = INF
                break
    ans = min(ans, num)

print(ans)
