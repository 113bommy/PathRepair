# セグメントツリー
#############################################################

def segfunc(x, y):
    return max(x, y)

ide_ele = 0

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
#############################################################


N, K = map(int, input().split())

# val[i] = 最後の値がiである、最長の部分列の長さ
val = [0] * 300010
seg = SegTree(val, segfunc, ide_ele)
ans = 0

for i in range(N):
    a = int(input())
    # (a-K, a-K+1, ..., a+K-1, a+K の max) + 1 に更新する
    # 両端が範囲内に収まるように調整
    l = max(a - K, 0)
    r = min(a + K, 300000)
    # 半開区間
    tmp = seg.query(l, r + 1) + 1
    ans = max(ans, tmp)
    seg.update(a, tmp)

print(ans)
