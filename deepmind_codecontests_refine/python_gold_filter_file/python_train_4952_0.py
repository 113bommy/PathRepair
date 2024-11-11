from collections import *
from sys import stdin


def arr_inp(n):
    if n == 1:
        return [int(x) for x in stdin.readline().split()]
    elif n == 2:
        return [float(x) for x in stdin.readline().split()]
    else:
        return list(stdin.readline()[:-1])


class graph:
    # initialize graph
    def __init__(self, gdict=None):
        if gdict is None:
            gdict = defaultdict(list)
        self.gdict, self.edges, self.l = gdict, [], defaultdict(int)

    # Get verticies
    def get_vertices(self):
        return list(self.gdict.keys())

    # add edge
    def add_edge(self, node1, node2, w=None):
        self.gdict[node1].append(node2)
        self.gdict[node2].append(node1)
        self.l[node1] += 1
        self.l[node2] += 1

    def bfs_util(self, i):
        queue, self.visit[i], color = deque([i]), 1, defaultdict(int, {c[i - 1]: 1})

        while queue:
            # dequeue parent vertix
            s = queue.popleft()

            # enqueue child vertices
            for i in self.gdict[s]:
                if self.visit[i] == 0:
                    queue.append(i)
                    self.visit[i] = 1
                    color[c[i - 1]] += 1
        # print(color)
        return sum(color.values()) - max(color.values())

    def bfs(self):
        self.visit, self.cnt = defaultdict(int), 0

        for i in self.get_vertices():
            if self.visit[i] == 0:
                self.cnt += self.bfs_util(i)

        return self.cnt


n, m, k = arr_inp(1)
c, g = arr_inp(1), graph()

for i in range(m):
    u, v = arr_inp(1)
    g.add_edge(u, v)

print(g.bfs())
