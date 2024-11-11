import sys
input = sys.stdin.readline
from collections import Counter

N = int(input())
state = [list(map(int, input().split())) for _ in range(3)]
graph = [[] for _ in range(N)]
for _ in range(N-1):
    a, b = map(int, input().split())
    graph[a-1].append(b-1)
    graph[b-1].append(a-1)

def bfs(s):
    D = [-1]*N
    D[s] = 0
    q = [s]
    while q:
        qq = []
        for p in q:
            for np in graph[p]:
                if D[np] == -1:
                    D[np] = D[p] + 1
                    qq.append(np)
        q = qq
    return D

D = bfs(0)
ind = -1
tmp = -1
for i in range(N):
    if D[i] > tmp:
        tmp = D[i]
        ind = i

D2 = bfs(ind)
C = Counter(D2)
ok = True
for c in C.values():
    if c != 1:
        ok = False
        break

if not ok:
    print(-1)
else:
    D3 = [None]*N
    for i in range(N):
        D3[D2[i]] = i
    ind0 = D3[0]
    ind1 = D3[1]
    PPP = []
    ans = 10**16
    for i1 in range(3):
        for i2 in range(3):
            if i1 == i2: continue
            score = state[i1][ind0] + state[i2][ind1]
            pre0 = i1
            pre1 = i2
            P = [i1, i2]
            for seq in range(2, N):
                now = 3 - pre0 - pre1
                P.append(now)
                score += state[now][D3[seq]]
                pre0 = pre1
                pre1 = now
            if score < ans:
                ans = score
                PPP = P
    toret = [None]*N
    for i, p in enumerate(PPP):
        toret[D3[i]] = p+1
    print(ans)
    print(*toret)
