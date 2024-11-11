INF = 10 ** 11
import sys
sys.setrecursionlimit(100000000)

N,M = map(int,input().split())
MOD = M
G = [[] for _ in range(N)]
for _ in range(N - 1):
    x,y = map(int,input().split())
    x -= 1
    y -= 1
    G[x].append(y)
    G[y].append(x)

deg = [0] * N
dp = [None] * N
parents = [0] * N
ans = [0] * N

def dfs(v,p = -1):
    deg[v] = len(G[v])
    res = 1
    dp[v] = [0] * deg[v]
    for i,e in enumerate(G[v]):
        if e == p:
            parents[v] = i
            continue
        dp[v][i] = dfs(e,v)
        res *= dp[v][i] + 1
        res %= MOD
    return res

def bfs(v,res_p = 0,p = -1):
    if p != -1:
        dp[v][parents[v]] = res_p
    dpl = [1]*(deg[v] + 1)
    dpr = [1]*(deg[v] + 1)
    for i in range(deg[v]):
        dpl[i + 1] = dpl[i]*(dp[v][i] + 1)%MOD
    for i in range(deg[v] - 1,-1,-1):
        dpr[i] = dpr[i + 1]*(dp[v][i] + 1)%MOD
    ans[v] = dpr[0]
    for i in range(deg[v]):
        e = G[v][i]
        if e == p:
            continue
        bfs(e,dpl[i]*dpr[i + 1]%MOD,v)

dfs(0)
bfs(0)
print('\n'.join(map(str,ans)))