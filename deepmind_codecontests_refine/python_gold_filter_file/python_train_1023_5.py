from collections import deque
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
            return 0
        if self.parents[x] > self.parents[y]:
            x, y = y, x
        self.parents[x] += self.parents[y]
        self.parents[y] = x
        
N = int(input())
xseq = []
yseq = []
uf = UnionFind(N)
ans = 0

for i in range(N):
    x,y = (int(x) for x in input().split())
    xseq.append((x,i))
    yseq.append((y,i))
xseq.sort()
yseq.sort()
xdiff = [(xseq[i][0]-xseq[i-1][0],(xseq[i][1],xseq[i-1][1])) for i in range(1,N)]
ydiff = [(yseq[i][0]-yseq[i-1][0],(yseq[i][1],yseq[i-1][1])) for i in range(1,N)]
diff = xdiff + ydiff
diff.sort()
d = deque(diff)

for i in range(len(d)):
    temp = d.popleft()
    if uf.find(temp[1][0]) != uf.find(temp[1][1]):
        uf.union(temp[1][0],temp[1][1])
        ans += temp[0]
print(ans)