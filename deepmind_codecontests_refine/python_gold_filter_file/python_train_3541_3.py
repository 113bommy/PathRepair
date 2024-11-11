import sys

NIL = -1

def set_depth(v, depth):
    tree[v][2] = depth
    
    for child in tree[v][1]:
        set_depth(child, depth + 1)

N = int(input())
tree = [[NIL, [], 0, 'leaf'] for _ in range(N)]

for _ in range(N):
    line = [int(i) for i in sys.stdin.readline().split()]
    t_id = line[0]
    children = line[2:]
    tree[t_id][1] = children
    
    if children:
        tree[t_id][3] = 'internal node'
    
    for child in children:
        tree[child][0] = t_id
        
for t_id in range(N):
    if tree[t_id][0] == NIL:
        tree[t_id][3] = 'root'
        r = t_id
        break

set_depth(r, 0)

for t_id in range(N):
    parent = tree[t_id][0]
    depth = tree[t_id][2]
    children = tree[t_id][1]
    type_t = tree[t_id][3]
    
    print('node {}: parent = {}, depth = {}, {}, {}'.format(t_id, parent, depth, type_t, children))