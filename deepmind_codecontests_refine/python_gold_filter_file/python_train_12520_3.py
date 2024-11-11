import sys
input = sys.stdin.buffer.readline
mod = 10**9+7

def main():
    t = int(input())

    for _ in range(t):
        n = int(input())
        g = [[] for _ in range(n)]
        for i in range(n-1):
            u, v = map(int, input().split())
            u, v = u-1, v-1
            g[u].append(v)
            g[v].append(u)
        m = int(input())
        P = list(map(int, input().split()))
        P.sort()

        s = []
        visit = [-1]*n
        s.append(0)
        order = []
        par = [-1]*n
        while s:
            v = s.pop()
            order.append(v)
            for u in g[v]:
                if u == par[v]:
                    continue
                par[u] = v
                s.append(u)

        ans = 0
        c = [1]*n
        order.reverse()
        U = []
        for v in order:
            if par[v] != -1:
                cnt = (n-c[v])*c[v]
                U.append(cnt)
                c[par[v]] += c[v]
        #print(U)
        if len(U) >= len(P):
            U.sort(reverse=True)
            ans = 0
            for u in U:
                if P:
                    p = P.pop()
                else:
                    p = 1
                ans += u*p
                ans %= mod
        else:
            U.sort()
            P.sort()
            Q = P[0:len(U)]
            R = P[len(U):]
            for r in R:
                Q[-1] *= r
                Q[-1] %= mod
            for u, q in zip(U, Q):
                ans += u*q
                ans %= mod
        print(ans)

if __name__ == '__main__':
    main()
