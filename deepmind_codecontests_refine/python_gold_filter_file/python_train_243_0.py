class BerlandRoads():
    def __init__(self, n, edges):
        self.n = n
        self.edges = edges
        self.parents = [i for i in range(n)]
        self.sizes = [1 for i in range(n)]

    def find(self, v):
        while self.parents[v] != v:
            temp = self.parents[v]
            self.parents[v] = self.parents[temp]
            v = temp
        return v

    def union(self, u, v):
        u = self.find(u)
        v = self.find(v)
        if u == v:
            return False
        else:
            if self.sizes[u] > self.sizes[v]:
                self.parents[v] = u
                self.sizes[u] += self.sizes[v]
            else:
                self.parents[u] = v
                self.sizes[v] += self.sizes[u]
            return True

    def build_roads(self):
        rem_edges = []
        for u,v in self.edges:
            if not self.union(u-1,v-1):
                rem_edges.append((u,v))
        tree_reps = []
        for i in range(n):
            if self.parents[i] == i:
                tree_reps.append(i+1)
        print(len(rem_edges))
        for i in range(len(rem_edges)):
            vals = [rem_edges[i][0],rem_edges[i][1],tree_reps[i], tree_reps[i+1]]
            print(*vals)

n = int(input())
edges = []
for i in range(n-1):
    u,v = list(map(int,input().strip(' ').split(' ')))
    edges.append((u,v))

br = BerlandRoads(n, edges)
br.build_roads()
                