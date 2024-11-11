import sys
input = sys.stdin.buffer.readline
INF = 0

class MaxSegTree:
    """
    0-indexed
    query : [L, R)
    """
    def __init__(self, size):
        self.size = 1 << (size.bit_length())  # 完全二分木にする
        self.data = [-INF] * (2 * self.size - 1)

    def build(self, rawData):
        self.data[self.size - 1: self.size - 1 + len(rawData)] = rawData
        for i in range(self.size - 1)[:: -1]:
            self.data[i] = max(self.data[2 * i + 1], self.data[2 * i + 2])

    def update(self, index, value):
        index += self.size - 1
        if self.data[index] >= value:
            return
        self.data[index] = value
        while index >= 0:
            index = (index - 1) // 2
            self.data[index] = max(self.data[2 * index + 1], self.data[2 * index + 2])

    def query(self, left, right):
        L = left + self.size
        R = right + self.size
        ret = -INF
        while L < R:
            if R & 1:
                R -= 1
                ret = max(ret, self.data[R - 1])
            if L & 1:
                ret = max(ret, self.data[L - 1])
                L += 1
            L >>= 1
            R >>= 1
        return ret

N, K = map(int, input().split())
A = [int(input()) for _ in range(N)]
mxA = max(A)
tree = MaxSegTree(mxA + 10)

for a in A:
    nx = tree.query(max(0, a - K), min(mxA, a + K) + 1)
    tree.update(a, nx + 1)

print(tree.query(0, mxA + 1))
