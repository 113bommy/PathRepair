import sys
input = sys.stdin.buffer.readline

MOD = 10 ** 9 + 7
INF = 2 * 10**18

in_n = lambda: int(input())
in_nn = lambda: map(int, input().split())
in_s = lambda: input().rstrip().decode('utf-8')
in_map = lambda: [s == ord('.') for s in input() if s != ord('\n')]


# 1点更新・区間クエリ（0-index）
class SegTree:

    def __init__(self, init_val, segfunc, ide_ele):

        n = len(init_val)
        self.segfunc = segfunc
        self.ide_ele = ide_ele
        self.num = 1 << (n - 1).bit_length()
        self.tree = [ide_ele] * 2 * self.num

        for i in range(n):
            self.tree[self.num + i] = init_val[i]

        for i in range(self.num - 1, 0, -1):
            self.tree[i] = self.segfunc(self.tree[2 * i], self.tree[2 * i + 1])

    def update(self, k, x):

        k += self.num
        self.tree[k] = x
        while k > 1:
            self.tree[k >> 1] = self.segfunc(self.tree[k], self.tree[k ^ 1])
            k >>= 1

    def query(self, l, r):

        res = self.ide_ele

        l += self.num
        r += self.num
        while l < r:
            if l & 1:
                res = self.segfunc(res, self.tree[l])
                l += 1
            if r & 1:
                res = self.segfunc(res, self.tree[r - 1])
            l >>= 1
            r >>= 1
        return res

    def get(self, k):
        k += self.num
        return self.tree[k]


def main():

    M = 3 * 10**5 + 10
    N, K = in_nn()
    A = [0] * N

    for i in range(N):
        A[i] = in_n()

    seg = SegTree([0] * M, segfunc=lambda a, b: max(a, b), ide_ele=0)

    for i in range(N):
        now = A[i]
        left = max(0, now - K)
        right = min(now + K + 1, M)
        u = seg.query(left, right)
        seg.update(now, u + 1)

    ans = seg.query(0, M)
    print(ans)


if __name__ == '__main__':
    main()
