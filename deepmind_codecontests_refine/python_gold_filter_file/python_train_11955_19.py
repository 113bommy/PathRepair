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

    def get_all_members(self):
        pare_d = {}
        for i in range(self.n):
            parent = self.find(i)
            pare_d.setdefault(parent,[])
            pare_d[parent].append(i)
        return list(pare_d.values())

    def __str__(self):
        return '\n'.join('{}: {}'.format(r, self.members(r)) for r in self.roots())



def main():
    n,m = map(int, input().split())
    al = list(map(int, input().split()))    
    uf = UnionFind(n)
    for _ in range(m):
        x,y = map(int, input().split())
        uf.union(x,y)

    first_mins = []
    other_vals = []
    
    all_members = uf.get_all_members()
    # all_members = list(uf.all_group_members())
    if len(all_members) == 1:
        print(0)
        exit()

    for members in all_members:
        vs = []
        for m in members:
            vs.append(al[m])
        vs.sort()
        first_mins.append(vs[0])
        for i,v in enumerate(vs[1:]):
            # if i > 0:
            other_vals.append(v)

    # print(first_mins)
    ans = 0
    ans += sum(first_mins)
    rem = len(all_members)-2
    if len(other_vals) < rem:
        print('Impossible')
        exit()
    other_vals.sort()
    ans += sum(other_vals[:rem])
    print(ans)



if __name__ == "__main__":
    main()