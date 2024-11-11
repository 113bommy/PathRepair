def modinv(x, mod):
    a, b = x, mod
    u, v = 1, 0
    while b:
        t = a // b
        a -= t * b; a, b = b, a
        u -= t * v; u, v = v, u
    return u % mod

def Lagrange_interpolation(X, Y, mod): # O(N**2)
    n = len(X) - 1
    for i in range(n+1):
        t = 1
        for j in range(n+1):
            if i != j:
                t = t * (X[i] - X[j]) % mod
        Y[i] = Y[i] * modinv(t, mod) % mod

    cur, nxt = 0, 1
    dp = [[0]*(n+2) for _ in range(2)]
    dp[0][0], dp[0][1] = -X[0], 1
    for i in range(1, n+1):
        for j in range(n+2):
            dp[nxt][j] = dp[cur][j] * -X[i] % mod
            if j:
                dp[nxt][j] = (dp[nxt][j] + dp[cur][j-1]) % mod
        cur, nxt = nxt, cur
    xinv = [modinv(v, mod) for v in X]
    ret = [0]*(n+1)
    for i in range(n+1):
        if Y[i] == 0:
            continue # 0割り対策
        if X[i] == 0:
            for j in range(n+1):
                ret[j] = (ret[j] + dp[cur][j+1] * Y[i]) % mod
        else:
            ret[0] = (ret[0] - dp[cur][0] * xinv[i] * Y[i]) % mod
            pre = -dp[cur][0] * xinv[i] % mod
            for j in range(1, n+1):
                ret[j] = (ret[j] - (dp[cur][j] - pre) * xinv[i] * Y[i]) % mod
                pre = (pre - dp[cur][j]) * xinv[i] % mod
    return ret

p = int(input())
a = list(map(int, input().split()))
x = list(range(p))
res = Lagrange_interpolation(x, a, p)
print(*res)