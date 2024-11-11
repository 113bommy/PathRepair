import sys
sys.setrecursionlimit(1000000000)
N = int(input())
AB = [list(map(int, input().split())) for _ in range(N - 1)]


class Tree:
    def __init__(self, v):
        self.v = v
        self.neighbors = []

    def set_rank(self, rank, parent):
        self.rank = rank
        for neighbor in self.neighbors:
            if neighbor is parent:
                continue
            neighbor.set_rank(rank=rank + 1, parent=self)


trees = {i: Tree(i) for i in range(1, N + 1)}

for a, b in AB:
    trees[a].neighbors.append(trees[b])
    trees[b].neighbors.append(trees[a])
try:
    trees[1].set_rank(1, None)
except:
    print(-1)
    exit()

group0 = [node.v for node in trees.values() if node.rank % 2 == 0]
group1 = [node.v for node in trees.values() if node.rank % 2]
x = [set(), set(), set()]
for i in range(1, N + 1):
    x[i % 3].add(i)
if len(group1) < len(group0):
    group1, group0 = group0, group1
result = {}
if len(group0) <= len(x[0]):
    while group0 and x[0]:
        result[group0.pop()] = x[0].pop()
    y = x[0] | x[1] | x[2]
    while group1 and y:
        result[group1.pop()] = y.pop()
else:
    while x[2] and group0:
        result[group0.pop()] = x[2].pop()
    while x[1] and group1:
        result[group1.pop()] = x[1].pop()
    while group0 and x[0]:
        result[group0.pop()] = x[0].pop()
    while group1 and x[0]:
        result[group1.pop()] = x[0].pop()
    if group0 or group1:
        print(-1)
        exit()

print(' '.join(str(result[i]) for i in range(1, N + 1)))