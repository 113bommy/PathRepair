import sys
sys.setrecursionlimit(100010)

N, M = map(int,input().split())
E = [[] for k in range(N)]

for k in range(M):
    X, Y, Z = map(int,input().split())
    E[X-1].append(Y-1)
    E[Y-1].append(X-1)
G = [-1]*N

def dfs(now,group):
    if G[now] == -1:
        G[now] = group
        for tsugi in E[now]:
            dfs(tsugi,group)

ans = 0
for k in range(N):
    if G[k] == -1:
        dfs(k,ans)
        ans += 1
print(ans)
