class Acc2D:
    def __init__(self, a, K):
        h, w = len(a), len(a[0])
        self.acc2D = self._build(h, w, a)
        self.K = K

    def _build(self, h, w, a):
        ret = [[0] * (w + 1) for _ in range(h + 1)]
        for r in range(h):
            for c in range(w):
                ret[r + 1][c + 1] = ret[r][c + 1] + ret[r + 1][c] - ret[r][c] + a[r][c]
                # 末項は必要に応じて改変すること
        return ret

    def get(self, r1, r2, c1, c2):
        # [r1,r2), [c1,c2) : 0-indexed
        if r1 < 0: r1 = 0
        if r2 >= self.K * 2: r2 = self.K * 2
        if c1 < 0: c1 = 0
        if c2 >= self.K * 2: c2 = self.K * 2
        acc2D = self.acc2D
        return acc2D[r2][c2] - acc2D[r1][c2] - acc2D[r2][c1] + acc2D[r1][c1]


def main():
    import sys
    input = sys.stdin.readline

    N, K = map(int, input().split())

    g = [[0] * (K * 2) for _ in range(K * 2)]
    for _ in range(N):
        x, y, c = input().split()
        x = int(x) % (K * 2)
        y = (int(y) - (K if c == 'B' else 0)) % (K * 2)
        g[x][y] += 1  # White

    acc2d = Acc2D(g, K)
    ans = -1
    for r in range(K):
        for c in range(K):
            t = acc2d.get(0, r, 0, c)
            t += acc2d.get(0, r, c + K, c + K * 2)
            t += acc2d.get(r, r + K, c, c + K)
            t += acc2d.get(r + K, r + K * 2, 0, c)
            t += acc2d.get(r + K, r + K * 2, c + K, c + K * 2)
            ans = max(ans, t, N - t)
    print(ans)


if __name__ == '__main__':
    main()

# import sys
# input = sys.stdin.readline
# 
# sys.setrecursionlimit(10 ** 7)
# 
# (int(x)-1 for x in input().split())
# rstrip()
