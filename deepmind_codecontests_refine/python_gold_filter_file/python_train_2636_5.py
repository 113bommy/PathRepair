import sys
input = sys.stdin.readline
from collections import Counter, deque, defaultdict
from itertools import permutations

class Fenwick:
    def __init__(self, n):
        self.tree = [0] * (n + 1)
        self.n = n

    def update(self, x, val):
        while x <= self.n:
            self.tree[x] += val
            x += x & -x

    def query(self, x):
        ans = 0
        while x:
            ans += self.tree[x]
            x -= x & -x
        return ans


for _ in range(int(input())):
    s = input()[:-1]
    n = len(s)
    cand = set(s)
    m = len(cand)
    cnt = Counter(s)
    ans = -1
    for idx in permutations(cand):
        cur = ""
        for x in idx:
            cur += x * cnt[x]
        dic = defaultdict(deque)
        for i, c in enumerate(s, 1):
            dic[c].append(i)
        A = []
        for c in cur:
            A.append(dic[c].popleft())
        bit = Fenwick(n)
        tot = 0
        for a in A:
            tot += bit.query(n) - bit.query(a)
            bit.update(a, 1)
        if tot > ans:
            ans = tot
            P = cur
    print(P)
