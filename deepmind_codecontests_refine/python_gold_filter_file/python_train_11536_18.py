class Bridge:
    def __init__(self, nodeA, nodeB):
        self.edges = [Edge(nodeA, self), Edge(nodeB, self)]
        nodeA.addEdge(self.edges[1])
        nodeB.addEdge(self.edges[0])
        self.dir = True
        self.vec = None
    def __repr__(self):
        return str((self.vec, self.dir))

class Edge:
    def __init__(self, node, bridge):
        self.bridge = bridge
        self.node = node
    def another(self):
        return self.bridge.edges[1 if self.bridge.edges[0] == self else 0]

class Node:
    def __init__(self, id):
        self.id = id
        self.edges = []
        self.parent = None
        self.judge = True
    def addEdge(self, edge):
        self.edges.append(edge)
    def __repr__(self):
        return str((self.id, None if self.parent is None else self.parent.node.id, self.judge))

N, M = map(int, input().split())

nodes = [Node(i) for i in range(N+1)]
bridges = []
for A, B in (map(int, input().split()) for _ in range(M)):
    bridges.append(Bridge(nodes[A], nodes[B]))

s = [nodes[1]]
idx = 0
while len(s) > 0:
    cur = s.pop()

    for nxt in cur.edges:
        if nxt.bridge.vec is None:
            cur.judge ^= True
            nxt.bridge.vec = (cur.id, nxt.node.id)
            if nxt.node.parent is None:
                nxt.node.parent = nxt.another()
                s.append(nxt.node)

    if len(s) > 0 and s[-1].parent is not None:
        nl = s[-1].parent.node
    else:
        nl = nodes[1]
    while cur.parent is not None and cur != nl:
        if not cur.judge:
            cur.judge ^= True
            cur.parent.node.judge ^= True
            cur.parent.bridge.dir ^= True
        cur = cur.parent.node
  
if nodes[1].judge:
    for br in bridges:
        if br.dir:
            print("{} {}".format(br.vec[0], br.vec[1]))
        else:
            print("{} {}".format(br.vec[1], br.vec[0]))
else:
    print("-1")
