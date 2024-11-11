# AC 回避した https://atcoder.jp/contests/abc137/submissions/6845103 の再提出

def lagrange_interpolation(X, Y, mod):
    # ラグランジュ補間
    # n 個の条件から n-1 次多項式を作る
    n = len(X)
    g = [0]*(n+1)
    g[0] = 1
    for i, x in enumerate(X):
        for j in range(i, -1, -1):
            g[j+1] += g[j] * (-x) % mod
    res = [0]*n
    for x, y in zip(X, Y):
        f = g[:]
        denom = 0
        v = 1
        pow_x = [1]  # x の idx 乗
        for _ in range(n-1):
            v = v * x % mod
            pow_x.append(v)
        pow_x.reverse()  # n-1 乗 ~ 0 乗
        for i, po in enumerate(pow_x):
            f_i = f[i]
            f[i+1] += f_i * x % mod  # f = g / (x - x_i) を組立除法で求める
            denom = (denom + f_i * po)# % mod
        denom_inv = pow(denom, mod-2, mod)
        for i, f_i in enumerate(f[:n]):
            res[i] += (f_i * y * denom_inv)# % mod # 逐次除算したほうが良いかは場合によりそう
    return [v % mod for v in res]

p = int(input())
A = list(map(int, input().split()))
ans = lagrange_interpolation(list(range(p)), A, p)
print(" ".join(map(str, ans[::-1])))
