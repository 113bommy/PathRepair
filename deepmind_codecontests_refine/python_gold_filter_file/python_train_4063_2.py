n, nq = map(int, input().split())
set_list = list(range(n))

def find(n):
    global set_list
    if set_list[n] == n:
        return n
    result = set_list[n] = find(set_list[n])
    return result

def same(x, y):
    set_list[find(y)] = find(x)

def unite(x, y):
    return find(x) == find(y)

for _ in range(nq):
    com,x,y = map(int, input().split())
    if com == 0:
        same(x, y)
    else:
        if unite(x, y):
            print(1)
        else:
            print(0)

