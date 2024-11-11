class UnionFind():
    # 作りたい要素数nで初期化
    def __init__(self, n):
        self.n = n
        self.root = [-1]*(n+1)
        self.rnk = [0]*(n+1)

    # ノードxのrootノードを見つける
    def Find_Root(self, x):
        if(self.root[x] < 0):
            return x
        else:
            self.root[x] = self.Find_Root(self.root[x])
            return self.root[x]
    
    # 木の併合、入力は併合したい各ノード
    def Unite(self, x, y):
        x = self.Find_Root(x)
        y = self.Find_Root(y)
        if(x == y):
            return 
        elif(self.rnk[x] > self.rnk[y]):
            self.root[x] += self.root[y]
            self.root[y] = x

        else:
            self.root[y] += self.root[x]
            self.root[x] = y
            if(self.rnk[x] == self.rnk[y]):
                self.rnk[y] += 1
    
    def isSameGroup(self, x, y):
        return self.Find_Root(x) == self.Find_Root(y)

    # ノードxが属する木のサイズ
    def Count(self, x):
        return -self.root[self.Find_Root(x)]

import sys
input = sys.stdin.buffer.readline
import heapq as hp

N = int(input())
XY = []
for i in range(N):
    x, y = map(int, input().split())
    XY.append((x, y, i))

XY.sort()

uni = UnionFind(N)
q = []
for x, y, i in XY:
    my = y
    while q and q[0][0] < y:
        jy, j = hp.heappop(q)
        my = min(jy, my)
        uni.Unite(i, j)
    hp.heappush(q, (my, uni.Find_Root(i)))

for i in range(N):
    print(uni.Count(i))