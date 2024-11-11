class UnionFind:
    def __init__(self, n):
        self.par = [-1 for i in range(n+1)]
        self.rank = [0] * (n+1)

    # 検索
    def find(self, x):
        if self.par[x] < 0:
            return x
        else:
            self.par[x] = self.find(self.par[x])
            return self.par[x]

    # 併合
    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)
        if not x==y: # 根が同じでない場合のみ併合する
            if self.rank[x] < self.rank[y]:
                self.par[y] += self.par[x] # 要素数を併合
                self.par[x] = y # 根を付け替えている
            else:
                self.par[x] += self.par[y]
                self.par[y] = x
                if self.rank[x] == self.rank[y]:
                    self.rank[x] += 1
        
    # 同じ集合に属するか判定
    def same_check(self, x, y):
        return self.find(x) == self.find(y) 

def main():
    import sys
    input = sys.stdin.readline
    
    N = int(input())
    from collections import defaultdict,deque
    G = defaultdict(list)
    D = []
    for i in range(N-1):
        a, b = map(int,input().split())
        D.append([a,b])
        G[a].append(b)
        G[b].append(a)
    
    que = deque()
    que.append(1)
    visited = {}
    oya = [-1]*(10**5+1)
    while que != deque():
        v = que.pop()
        visited[v] = 1
        if v == N:
            break
        else:
            for i in G[v]:
                if not i in visited:
                    oya[i] = v
                    que.append(i)
    now = N
    path = []
    while now != -1:
        path.append(now)
        now = oya[now]
    path = path[::-1]
    #print(path)
    L = len(path)
    if L%2==0:
        d1,d2 = path[L//2-1],path[L//2]
    else:
        d1,d2 = path[L//2],path[L//2+1]
    G2 = UnionFind(N)
    
    for i in D:
        a,b = i
        if not {a,b} == {d1,d2}:
            G2.union(a,b)
    one = -G2.par[G2.find(1)]
    enu = -G2.par[G2.find(N)]
    
    if one>enu:
        print("Fennec")
    else:
        print("Snuke")
    

main()