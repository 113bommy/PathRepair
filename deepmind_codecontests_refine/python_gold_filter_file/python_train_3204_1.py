#Union Find

#xの根を求める
def find(x):
    if par[x] < 0:
        return x
    else:
        tank = []
        while par[x] >= 0:
            tank.append(x)
            x = par[x]
        for elt in tank:
            par[elt] = x
        return x
#xとyの属する集合の併合
def unite(x,y):
    x = find(x)
    y = find(y)
    
    if x == y:
        return False
    else:
        #sizeの大きいほうがx
        if par[x] > par[y]:
            x,y = y,x
        par[x] += par[y]
        par[y] = x
        return True

#xとyが同じ集合に属するかの判定
def same(x,y):
    return find(x) == find(y)

#xが属する集合の個数
def size(x):
    return -par[find(x)]


import sys
input = sys.stdin.readline

n,q = map(int,input().split())

#初期化
#根なら-size,子なら親の頂点
par = [-1]*n

for i in range(q):
    t,u,v = map(int,input().split())
    if t == 0:
        unite(u,v)
    elif same(u,v):
        print(1)
    else:
        print(0)