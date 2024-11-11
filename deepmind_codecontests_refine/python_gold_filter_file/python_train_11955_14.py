N,M = map(int,input().split())
src = list(map(int,input().split()))
es = [tuple(map(int,input().split())) for i in range(M)]

if M == N-1:
    print(0)
    exit()
if M + N//2 < N-1:
    print('Impossible')
    exit()

parent = [i for i in range(N)]
rank = [0] * N
def root(a):
    if parent[a] == a:
        return a
    else:
        parent[a] = root(parent[a])
        return parent[a]
def same(a,b):
    return root(a) == root(b)
def unite(a,b):
    ra = root(a)
    rb = root(b)
    if ra == rb: return
    if rank[ra] < rank[rb]:
        parent[ra] = rb
    else:
        parent[rb] = ra
        if rank[ra] == rank[rb]: rank[ra] += 1

for a,b in es:
    unite(a,b)
trees = {}
for i in range(N):
    trees[root(i)] = False

costs = []
for i,c in enumerate(src):
    costs.append((c,i))
costs.sort()

used = [False] * N
ans = used_n = 0
for c,v in costs:
    t = root(v)
    if trees[t]:
        continue
    else:
        trees[t] = used[v] = True
        used_n += 1
        ans += c

for c,v in costs:
    if used_n == 2*(N-M-1): break
    if used[v]: continue
    used_n += 1
    ans += c
print(ans)
