import sys
input = lambda : sys.stdin.readline().rstrip()
sys.setrecursionlimit(max(1000, 10**9))
write = lambda x: sys.stdout.write(x+"\n")



class UnionFindTree:
    def __init__(self, n):
        self.n = n
        self.parent = list(range(n))
        self.size = [1] * n

    def root(self, i):
        inter = set()
        while self.parent[i]!=i:
            inter.add(i)
            i = self.parent[i]
        r = i
        for i in inter:
            self.parent[i] = r
        return r

    def connect(self, i, j):
        if i==j:
            return
        ri = self.root(i)
        rj = self.root(j)
        if ri==rj:
            return
        if self.size[ri]<self.size[rj]:
            self.parent[ri] = rj
            self.size[rj] += self.size[ri]
        else:
            self.parent[rj] = ri
            self.size[ri] += self.size[rj]


n = int(input())
uf = UnionFindTree(n)
ps = list(map(int, input().split()))
k = 0
for i,p in enumerate(ps):
    if p<0:
        k += 1
        continue
    uf.connect(i,p-1)
for i in range(n):
    uf.root(i)
from collections import Counter, defaultdict
M = 10**9+7
ncount = Counter(uf.parent)
mcount = defaultdict(int)
for i,g in enumerate(uf.parent):
    if ps[i]==-1:
        mcount[g] += 1

ans = sum(v-1 for v in ncount.values())
ans *= pow(n-1, k, M)

for kk in ncount.keys():
    ncount[kk] -= mcount[kk]

for kk,mm in mcount.items():
    if mm==0:
        continue
    nn = ncount[kk]
    ans += (n - mm - nn)*pow(n-1, k-1, M)*mm
    ans %= M

nums = [nn+mcount[k] for k,nn in ncount.items() if mcount[k]]
l = len(nums)
dp = [[0] * l for _ in range(l)]
# dp[i][j] : i番目まで使うときの周期j+1の個数
if nums:
    dp[0][0] = nums[0]
    for i in range(1,l):
        dp[i][0] = dp[i-1][0] + nums[i]

    for i in range(1,l):
        for j in range(1,l):
            dp[i][j] += dp[i-1][j-1] * nums[i] * j + dp[i-1][j]
            dp[i][j] %= M

    for j in range(1, l):
        ans -= dp[-1][j]*pow(n-1, l-j-1, M)

print(ans%M)
    