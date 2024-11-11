# 方針
# 頂点uからvに至る際に通る辺のリストをe[u][v]とする。
# M個の制約からl個(l>=1)選んだ際に，いずれの制約も満たさないために白く塗るべき辺の個数を考える。
# これは,uiからviに至る際に通る辺のリストの和集合の要素の数。

from collections import deque

N = int(input())
adj = [[] for i in range(N + 1)] # 1-ind
ve = {} # 両端の頂点の番号⇒辺の番号
for i in range(1, N) : # 1-ind
    a, b = map(int,input().split())
    adj[a].append(b); adj[b].append(a)
    ve[(a, b)] = ve[(b, a)] = i
# print(adj) #DB
# print(ve) #DB

# 頂点iからスタートし，葉に行き着くまでの通過頂点とそれまでに通過した辺を記録
l = [[set() for j in range(N + 1)] for i in range(N + 1)]
q = deque()
for i in range(1, N + 1):
    r = [False] * (N + 1)
    q.append(i); r[i] = True
    while q:
        u = q.popleft()
        for v in adj[u]:
            if r[v]:
                continue
            l[i][v].update(l[i][u])            
            l[i][v].add(ve[(u, v)])
            q.append(v)
            r[v] = True
# print(l) #DB
'''
for i in range(1, N + 1):
    for j in range(i, N + 1):
        print(i, j, l[i][j])
'''
M = int(input())
c = [set()]
for i in range(1, M + 1): # 1-ind
    u, v = map(int,input().split())
    c.append((u, v))

ans = 2 ** (N - 1)
for k in range(1, 1 << M): # 制約0個の場合を除外 ※初期値で考慮することもできそう
    V = set()
    d = 0 # 考慮する制約の個数
    for i in range(1, M + 1):
        if k >> (i - 1) & 1:
            d += 1
            u, v = c[i]
            V |= l[u][v]
    # print(k, V)
    temp = 2 ** (N - 1 - len(V))
    # print(d, temp)
    if d % 2 == 1:
        ans -= temp
    elif d % 2 == 0:
        ans += temp

print(ans)