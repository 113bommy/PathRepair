N, M = map(int,input().split())
par = [i for i in range(N+1)]
size = [1 for _ in range(N+1)]

def find(x):
    if par[x] == x:
        return x
    else:
        par[x] = find(par[x])
        return par[x]

def unite(x,y):
    x = find(x)
    y = find(y)
    if x == y:
        return 1
    par[x] = y
    size[y] += size[x]
    size[x] = 0

for i in range(M):
    x, y, z= map(int,input().split())
    unite(x,y)

Ans = 0
for j in size[1:]:
    if j != 0:
        Ans += 1
print(Ans)
