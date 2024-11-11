import sys
import io, os
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

def main():

    N = 10**6
    mod = 998244353
    fac = [1]*(N+1)
    finv = [1]*(N+1)
    for i in range(N):
        fac[i+1] = fac[i] * (i+1) % mod
    finv[-1] = pow(fac[-1], mod-2, mod)
    for i in reversed(range(N)):
        finv[i] = finv[i+1] * (i+1) % mod

    def cmb1(n, r, mod):
        if r <0 or r > n:
            return 0
        r = min(r, n-r)
        return fac[n] * finv[r] * finv[n-r] % mod

    n = int(input())
    g = [[] for i in range(n)]
    ind = [0]*n
    for i in range(n-1):
        u, v = map(int, input().split())
        u, v = u-1, v-1
        g[u].append(v)
        g[v].append(u)
        ind[u] += 1
        ind[v] += 1

    M = max(ind)
    for i in range(n):
        if ind[i] == M:
            s = i
            break
    #print(s)
    stack = []
    stack.append(s)
    depth = [-1]*n
    depth[s] = 0
    par = [-1]*n
    order = []
    while stack:
        v = stack.pop()
        order.append(v)
        for u in g[v]:
            if u == par[v]:
                continue
            depth[u] = depth[v]+1
            par[u] = v
            stack.append(u)
    C = [1]*n
    order.reverse()
    for v in order:
        if par[v] != -1:
            C[par[v]] += 1
    dp = [1]*n
    for v in order:
        if par[v] != -1:
            dp[v] *= fac[C[v]]
            dp[v] %= mod
            dp[par[v]] *= dp[v]
            dp[par[v]] %= mod
        else:
            dp[v] *= n
            dp[v] *= fac[C[v]-1]
    print(dp[s]%mod)

if __name__ == '__main__':
    main()
