#!/usr/bin/env python3
import sys
from functools import lru_cache
sys.setrecursionlimit(10**8)
INF = float("inf")

MOD = 1000000007  # type: int


@lru_cache(maxsize=None)
def factorial(n):
    if n == 0:
        return 1
    else:
        return (n*factorial(n-1)) % MOD


class UnionFind():
    def __init__(self, n):
        self.n = n
        self.parents = [-1] * n

    def find(self, x):
        if self.parents[x] < 0:
            return x
        else:
            self.parents[x] = self.find(self.parents[x])
            return self.parents[x]

    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)

        if x == y:
            return

        if self.parents[x] > self.parents[y]:
            x, y = y, x

        self.parents[x] += self.parents[y]
        self.parents[y] = x

    def size(self, x):
        return -self.parents[self.find(x)]

    def same(self, x, y):
        return self.find(x) == self.find(y)

    def members(self, x):
        root = self.find(x)
        return [i for i in range(self.n) if self.find(i) == root]

    def roots(self):
        return [i for i, x in enumerate(self.parents) if x < 0]

    def group_count(self):
        return len(self.roots())

    def all_group_members(self):
        return {r: self.members(r) for r in self.roots()}

    def __str__(self):
        return '\n'.join('{}: {}'.format(r, self.members(r)) for r in self.roots())


def main():
    N = int(input())
    P = list(map(int, input().split()))

    # 確定している道でグルーピングする
    uf = UnionFind(N)

    K = 0
    undef = []
    for i, p in enumerate(P):
        if p != -1:
            uf.union(i, p-1)
        else:
            K += 1
            undef.append(i)

    groups = {}
    mapping = {}
    for i, r in enumerate(uf.roots()):
        groups[r] = [uf.size(r), True]
        mapping[i] = r
    for u in undef:
        groups[uf.find(u)][1] = False

    # 作り直し（むだっぽい）
    size_all = []
    looped = []
    size_undef = []
    for k, v in groups.items():
        size_all.append(v[0])
        looped.append(v[1])
        if v[1] == False:
            size_undef.append(v[0])
    # print(size_all)
    # print(looped)

    # dp[i, j]: i個の根付き木を見てj個を選んだ時の\sum{\prod_v S_v}
    dp = [0]*(K+1)
    dp[0] = 1
    dp_new = dp[:]
    for i in range(1, K+1):
        for j in range(i):
            dp_new[j+1] += dp[j]*size_undef[i-1]
        dp = dp_new[:]
        # print("dpしたときのdp", dp)

    # ただしj=1個を選んだ時のものは特別にsize[i]-1を考える必要がある
    if K >= 1:
        tot = 0
        for s in size_undef:
            tot += s-1
        dp[1] = tot
        # print("j==1のケースを修正後dp", dp)

    cycle_count = 0
    for i in range(1, K+1):
        # i個のグループからなるサイクルがひとつできる
        buf = dp[i]*factorial(i-1)
        buf %= MOD
        buf *= pow(N-1, K-i, MOD)
        buf %= MOD
        cycle_count += buf
        # print("数え上げ", dp[i], factorial(i-1), pow(N-1, K-i, MOD))
    # print(f"cycle_count, {cycle_count}")

    # すでに固定サイクルがあれば数える
    cycle_count += (len(groups)-K)*pow(N-1, K, MOD)

    # \sigma_{つなぎ方} N
    ans = N*pow(N-1, K, MOD)
    # print("sigma_{つなぎ方} N", ans)
    ans %= MOD
    ans = ans - cycle_count
    ans %= MOD

    print(ans)

    return


if __name__ == '__main__':
    main()
