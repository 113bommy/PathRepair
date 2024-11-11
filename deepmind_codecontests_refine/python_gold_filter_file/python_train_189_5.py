from collections import defaultdict
def inpl(): return [int(i) for i in input().split()]
class BIT:
    def __init__(self, n):
        self.size = n
        self.tree = [0] * (n + 1)
 
    def sumi(self, i):
        s = 0
        while i > 0:
            s += self.tree[i]
            i -= i & -i
        return s
 
    def add(self, i, x):
        while i <= self.size:
            self.tree[i] += x
            i += i & -i

N, M = inpl()
H = defaultdict(lambda: [])
for _ in range(N):
    l, r = inpl()
    H[r-l+1].append(l)
Q = BIT(M+1)
ctr = N
for i in range(1,M+1):
    ctr -= len(H[i]) 
    for j in H[i]:
        Q.add(j, 1)
        Q.add(j+i, -1)
    ans = 0
    for k in range(i,M+1,i):
        ans += Q.sumi(k)
    print(ctr + ans)