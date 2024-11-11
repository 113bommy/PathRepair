class UnionFind:
    def __init__(self, n):
        self.par = [i for i in range(n+1)]
        self.rank = [0] * (n+1)

    # 検索
    def find(self, x):
        if self.par[x] == x:
            return x
        else:
            self.par[x] = self.find(self.par[x])
            return self.par[x]

    # 併合
    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)
        if self.rank[x] < self.rank[y]:
            self.par[x] = y
        else:
            self.par[y] = x
            if self.rank[x] == self.rank[y]:
                self.rank[x] += 1

    # 同じ集合に属するか判定
    def same_check(self, x, y):
        return self.find(x) == self.find(y)

    def ans(self):
        print(len(set(self.par))-1)

n,m=map(int,input().split())
uf=UnionFind(n)

for i in range(m):
    a,b=map(int,input().split())
    uf.union(a,b)
a=1
b=1
c=0
for i in range(3,n+1):
    if uf.same_check(1,i):
        a+=1
    elif uf.same_check(2,i):
        b+=1
    else:
        c+=1
if a>b:
    a+=c
else:
    b+=c
print(a*(a-1)//2+b*(b-1)//2-m)

