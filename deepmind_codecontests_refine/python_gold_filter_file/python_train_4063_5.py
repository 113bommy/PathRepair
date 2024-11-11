n,q = map(int, input().split())

root_list = [i for i in range(n)]

def root(x):
    path_to_root = []
    while root_list[x] != x:
        path_to_root.append(x)
        x = root_list[x]
    for node in path_to_root:
        root_list[node] = x
    return x

def is_same_set(x,y):
    return root(x) == root(y)

def unite(x,y):
    root_list[root(x)] = root(y)

for _ in range(q):
    com, x, y = map(int, input().split())
    if com == 0:
        #unite
        unite(x,y)
    else:
        if is_same_set(x,y):
            print(1)
        else:
            print(0)
