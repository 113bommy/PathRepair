import sys


class SegTreeMax:
    """
    以下のクエリを処理する
    1.update:  i番目の値をxに更新する
    2.get_min: 区間[l, r)の最小値を得る
    """

    def __init__(self, n, INF):
        """
        :param n: 要素数
        :param INF: 初期値（入りうる要素より十分に大きな数）
        """
        n2 = 1 << (n - 1).bit_length()
        self.offset = n2
        self.tree = [INF] * (n2 << 1)
        self.INF = INF

    @classmethod
    def from_array(cls, arr, INF):
        ins = cls(len(arr), INF)
        ins.tree[ins.offset:ins.offset + len(arr)] = arr
        for i in range(ins.offset - 1, 0, -1):
            l = i << 1
            r = l + 1
            ins.tree[i] = max(ins.tree[l], ins.tree[r])
        return ins

    def update(self, i, x):
        """
        i番目の値をxに更新
        :param i: index(0-indexed)
        :param x: update value
        """
        i += self.offset
        self.tree[i] = x
        while i > 1:
            y = self.tree[i ^ 1]
            if y >= x:
                break
            i >>= 1
            self.tree[i] = x

    def get_max(self, a, b):
        """
        [a, b)の最大値を得る
        :param a: index(0-indexed)
        :param b: index(0-indexed)
        """
        result = self.INF

        l = a + self.offset
        r = b + self.offset
        while l < r:
            if r & 1:
                result = max(result, self.tree[r - 1])
            if l & 1:
                result = max(result, self.tree[l])
                l += 1
            l >>= 1
            r >>= 1

        return result


n, k, *aaa = map(int, sys.stdin.buffer.read().split())

sgt = SegTreeMax(300001, 0)
for a in aaa:
    nxt = sgt.get_max(max(0, a - k), min(a + k + 1, 300001))
    sgt.update(a, nxt + 1)
print(sgt.get_max(0, 300001))
