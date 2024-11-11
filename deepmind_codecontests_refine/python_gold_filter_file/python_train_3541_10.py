# -*- coding: utf-8 -*-
N = int(input())
tree = {n:{} for n in range(N)}
children = set()

for n in range(N):
    inp = [int(m) for m in input().split()]
    tree[inp[0]]["leaf"] = inp[2:]
    children.update(inp[2:])

parent = set([n for n in range(N)]).difference(children).pop()
tree[parent]["depth"] = 0
tree[parent]["parent"] = -1

siblings = tree[parent]["leaf"]
for c in siblings:
    tree[c]["depth"] = 1
    tree[c]["parent"] = parent

depth = 2
while len(children):
    children = children.difference(siblings)
    next_gen = []
    for s in siblings:
        next_gen.extend(tree[s]["leaf"])
        for c in tree[s]["leaf"]:
            tree[c]["depth"] = depth
            tree[c]["parent"] = s
    siblings = next_gen
    depth += 1

    
for n in range(N):
    if tree[n]["depth"] == 0:
        tree[n]["type"] = "root"
    elif tree[n]["leaf"] == []:
        tree[n]["type"] = "leaf"
    else:
        tree[n]["type"] = "internal node"
        
    print("node {}: parent = {}, depth = {}, {}, {}" \
              .format(n, tree[n]["parent"], tree[n]["depth"], tree[n]["type"], tree[n]["leaf"]))