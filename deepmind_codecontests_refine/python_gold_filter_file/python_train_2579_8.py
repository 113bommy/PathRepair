class UnionFind:
    def __init__(self, n):
        self.table = [-1] * n

    def _root(self, x):
        stack = []
        tbl = self.table
        while tbl[x] >= 0:
            stack.append(x)
            x = tbl[x]
        for y in stack:
            tbl[y] = x
        return x

    def find(self, x, y):
        return self._root(x) == self._root(y)

    def unite(self, x, y):
        r1 = self._root(x)
        r2 = self._root(y)
        if r1 == r2:
            return
        d1 = self.table[r1]
        d2 = self.table[r2]
        if d1 <= d2:
            self.table[r2] = r1
            self.table[r1] += d2
        else:
            self.table[r1] = r2
            self.table[r2] += d1

    def get_size(self, x):
        return -self.table[self._root(x)]


n = int(input())
ppp = list(map(int, input().split()))
MOD = 10 ** 9 + 7
uft = UnionFind(n)
base = 0
undefined = []
for i, p in enumerate(ppp):
    if p == -1:
        undefined.append(i)
        continue
    p -= 1
    if not uft.find(i, p):
        base += 1
        uft.unite(i, p)

if len(undefined) == 0:
    print(base % MOD)
    exit()
elif len(undefined) == 1:
    c = uft.get_size(undefined[0])
    others = n - c
    print((base * (n - 1) + others) % MOD)
    exit()

m = len(undefined)
dp = [0] * (m + 1)  # 閉路のパターン数
dp[0] = 1
additional = 0  # 閉路を考慮せずに追加される辺数

for i in undefined:
    c = uft.get_size(i)
    for j in range(m - 1, -1, -1):
        dp[j + 1] += dp[j] * c
    additional += n - c

duplicated = 0
pat = pow(n - 1, m, MOD)
inv = pow(n - 1, MOD - 2, MOD)
loop_permutation = 1
loop_other_pattern = pat * inv * inv % MOD
for loop_size in range(2, m + 1):
    duplicated = (duplicated + dp[loop_size] * loop_permutation * loop_other_pattern) % MOD
    loop_other_pattern = loop_other_pattern * inv % MOD
    loop_permutation = loop_permutation * loop_size % MOD

ans = (base * pat + additional * pat * inv - duplicated) % MOD

print(ans)
