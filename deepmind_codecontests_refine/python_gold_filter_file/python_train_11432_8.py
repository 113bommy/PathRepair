# N! 通りの総和は期待値で考えたほうがわかりやすくなることが多そう

import sys
from functools import lru_cache
sys.setrecursionlimit(500000)

def make_modinv_list(n, mod=10**9+7):
    # 0 から n までの mod 逆元のリストを返す O(n)
    modinv = [0, 1]
    for i in range(2, n+1):
        modinv.append(mod - mod//i * modinv[mod%i] % mod)
    return modinv

def main():
    modinv = make_modinv_list(200)

    @lru_cache(maxsize=None)
    def solve(idx, X):
        # 降順ソートした S の idx 個目以降を使ったときの操作後の X の期待値
        if idx == N:
            return X
        # idx 個目を idx 個目以降で最初に使うかで場合分け
        res = 0
        # 最初に使う場合（確率 (1/(N-idx))）
        res += modinv[N-idx] * solve(idx+1, X % S[idx]) % mod
        # 最初に使わない場合（確率 ((N-idx-1)/(N-idx))）
        res += (N-idx-1) * modinv[N-idx] * solve(idx+1, X) % mod
        return res % mod

    mod = 10**9+7
    N, X = map(int, input().split())
    S = sorted(map(int, input().split()), reverse=True)
    ans = solve(0, X)
    for i in range(2, N+1):
        ans = ans * i % mod
    print(ans)

main()
