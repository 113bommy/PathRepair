class RMQ:
    def __init__(self, length, ini_num = float("inf")):
        self.length = 1
        while self.length < length:
            self.length <<= 1
        self.segtree = [ini_num] * (2 * self.length - 1)

    def update(self, index, n):
        leaf_index = index + self.length - 1
        self.segtree[leaf_index] = n
        while leaf_index > 0:
            leaf_index = (leaf_index - 1) // 2
            self.segtree[leaf_index] = min(self.segtree[leaf_index * 2 + 1], self.segtree[leaf_index * 2 + 2])

    def find(self, a, b, index, l, r):
        if a == b:
            return self.segtree[self.length - 1 + a]
        elif a <= l <= r <= b:
            return self.segtree[index]
        elif b < l or r < a:
            return float("inf")
        else:
            return min(self.find(a, b, index * 2 + 1, l, (l + r) // 2), self.find(a, b, index * 2 + 2, (l + r) // 2 + 1, r))

v_num, query = (int(n) for n in input().split(" "))
rmq = RMQ(v_num, 2147483647)
for _ in range(query):
    com, i, n = (int(n) for n in input().split(" ") )
    if com == 0:
        rmq.update(i, n)
    else:
        print(rmq.find(i, n, 0, 0, rmq.length - 1))