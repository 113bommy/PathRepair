import sys
sys.setrecursionlimit(1000000)
input = sys.stdin.readline
from bisect import bisect_right as br
N, K = map(int, input().split())
X = [[] for i in range(N)]
for i in range(N-1):
    x, y, c, d = map(int, input().split())
    X[x-1].append((y-1, c-1, d))
    X[y-1].append((x-1, c-1, d))

P = [(-1, 0, 0)] * N
Q = [(0, 0, 0)]
R = []
ET = []
ct = 0
CT = [0] * (N-1) * 2
CTA = [-1]* N
BT = [[[-1], [0], [0]] for _ in range(N)]
while Q:
    i, c, d = Q.pop()
    if i < 0:
        BT[c][0].append(ct)
        BT[c][1].append(BT[c][1][-1]-1)
        BT[c][2].append(BT[c][2][-1]-d)
        ct += 1
        continue
    R.append(i)
    if i > 0:
        if CTA[i] < 0: CTA[i] = ct
        BT[c][0].append(ct)
        BT[c][1].append(BT[c][1][-1]+1)
        BT[c][2].append(BT[c][2][-1]+d)
        ct += 1
    
    for a, c, d in X[i][::-1]:
        if a != P[i][0]:
            ET.append((i, a))
            P[a] = (i, c, d)
            for k in range(len(X[a])):
                if X[a][k][0] == i:
                    del X[a][k]
                    break
            Q.append((~a, c, d))
            Q.append((a, c, d))

L = [[0, 0] for _ in range(N)]
for i in R[1:]:
    p, c, d = P[i]
    L[i][0] = L[p][0] + 1
    L[i][1] = L[p][1] + d

D = [[P[i][0] for i in range(N)]] + [[-1]*N for _ in range(16)]
for k in range(1, 17):
    for i in range(N):
        a = D[k-1][i]
        if a > 0:
            D[k][i] = D[k-1][a]

def lca(u0, v0):
    u, v = u0, v0
    if L[u][0] < L[v][0]:
        u, v = v, u
    
    while L[u][0] > L[v][0]:
        d = L[u][0] - L[v][0]
        dd = d.bit_length() - 1
        u = D[dd][u]
    if u == v:
        return u
    
    for i in range(17)[::-1]:
        if D[i][u] != D[i][v]:
            u = D[i][u]
            v = D[i][v]
    
    return D[0][u]
    

def calc(x, y, w):
    aa = br(BT[x][0], CTA[w]) - 1
    c = BT[x][1][aa]
    d = BT[x][2][aa]
    return L[w][1] + c*y - d

for _ in range(K):
    x, y, u, v = map(int, input().split())
    x, u, v = x-1, u-1, v-1
    ll = lca(u, v)
    print(calc(x, y, u) + calc(x, y, v) - 2*calc(x, y, ll))
