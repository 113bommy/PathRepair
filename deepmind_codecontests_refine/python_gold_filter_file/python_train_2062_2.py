def union_find():
    # グラフの連結していないグループの数をunion_findで求める
    def get_parent(node):
        if par[node] == -1:
            return node
        else:
            par[node] = get_parent(par[node])
            return par[node]

    def merge(i, j):
        i = get_parent(i)
        j = get_parent(j)
        if i != j:
            par[j] = i
        return

    n, m = map(int, input().split())
    xyz = [list(map(int, input().split())) for _ in range(m)]
    par = [-1] * n
    for x, y, z in xyz:
        merge(x-1, y-1)
    print(par.count(-1))

union_find()