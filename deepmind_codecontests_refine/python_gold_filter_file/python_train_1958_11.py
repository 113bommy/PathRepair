import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**5)

N, Q = map(int, input().split())

path = [[] for _ in range(N)]

for _ in range(N-1) :
    a, b, c, d = (int(i) for i in input().split())
    path[a-1].append((b-1, c-1, d))
    path[b-1].append((a-1, c-1, d))

# doublingに必要なKを求める
for K in range(18) :
    if 2 ** K >= N :
        break

# dfs
parent = [[-1] * N for _ in range(K)]
rank = [-1 for _ in range(N)]

rank[0] = 0
queue = [0]

while queue :
    cur = queue.pop()
    for nex, _, _ in path[cur] :
        if rank[nex] < 0 :
            queue.append(nex)
            parent[0][nex] = cur
            rank[nex] = rank[cur] + 1

# doubling        
for i in range(1, K) :
    for j in range(N) :
        if parent[i-1][j] > 0 :
            parent[i][j] = parent[i-1][parent[i-1][j]]

# lca
def lca(a, b) :
    if rank[a] > rank[b] :
        a, b = b, a

    diff = rank[b] - rank[a]
    i = 0
    while diff > 0 :
        if diff & 1 :
            b = parent[i][b]
        diff >>= 1
        i += 1
        
    if a == b :
        return a

    for i in range(K-1, -1, -1) :
        if parent[i][a] != parent[i][b] :
            a = parent[i][a]
            b = parent[i][b]

    return parent[0][a]

# Queryの先読み
schedule = [[] for _ in range(N)]
for i in range(Q) : 
    x, y, u, v = map(int, input().split())
    x, u, v = x-1, u-1, v-1
    l = lca(u, v)
    schedule[u].append((i, 1, x, y))
    schedule[v].append((i, 1, x, y))
    schedule[l].append((i, -2, x, y))

ret = [0] * Q
C = [0] * (N-1)
D = [0] * (N-1)

def dfs(cur, pre, tot) :
    for i, t, c, d in schedule[cur] :
        ret[i] += t * (tot - D[c] + C[c] * d)
    
    for nex, c, d in path[cur] :
        if nex == pre :
            continue
        C[c] += 1
        D[c] += d
        dfs(nex, cur, tot + d)
        C[c] -= 1
        D[c] -= d

dfs(0, -1, 0)
   
for i in range(Q) :
    print(ret[i])