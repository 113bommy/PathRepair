def main():
    from sys import stdin
    input = stdin.readline
    mod = 10**9+7
    n = int(input())
    ab = [list(map(int, input().split())) for _ in [0]*(n-1)]
    pow2 = [1]
    for i in range(200000):
        pow2.append(pow2[-1]*2 % mod)

    g = [set() for _ in [0]*n]
    [g[a-1].add(b-1) for a, b in ab]
    [g[b-1].add(a-1) for a, b in ab]
    root = 0
    d = [-1]*n
    d[root] = 0
    q = [root]
    cnt = 0
    while q:
        cnt += 1
        qq = []
        while q:
            i = q.pop()
            for j in g[i]:
                if d[j] == -1:
                    d[j] = cnt
                    qq.append(j)
        q = qq

    for i in range(n):
        di = d[i]
        remove_list = []
        for j in g[i]:
            if di > d[j]:
                remove_list.append(j)
        for j in remove_list:
            g[i].remove(j)
    dd = sorted([(j, i) for i, j in enumerate(d)])[::-1]
    dd = [j for i, j in dd]

    dp = [(0, 0, 1) for _ in [0]*n]
    for i in dd:
        if g:
            n = 1
            for j in g[i]:
                if j != i:
                    n += dp[j][2]
            x, y = pow(2, n-1, mod)-1, 0
            for j in g[i]:
                if j != i:
                    xj, yj, nj = dp[j]
                    p1, p2 = pow2[n-nj], pow2[nj]
                    x += xj*p1+yj*(p1-1)-p2+1
                    y += yj+p2-1
            dp[i] = (x % mod, y % mod, n)

    x = dp[0][0]
    y = pow(2, dp[0][2], mod)
    print(x*pow(y, mod-2, mod) % mod)


main()
