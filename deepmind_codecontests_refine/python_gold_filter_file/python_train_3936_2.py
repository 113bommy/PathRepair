import os
import sys

if os.getenv("LOCAL"):
    sys.stdin = open("_in.txt", "r")

sys.setrecursionlimit(2147483647)
INF = float("inf")
IINF = 10 ** 18
MOD = 998244353

N, M = list(map(int, sys.stdin.readline().split()))


def get_factorials(max, mod=None):
    """
    階乗 0!, 1!, 2!, ..., max!
    :param int max:
    :param int mod:
    :return:
    """
    ret = [1]
    n = 1
    if mod:
        for i in range(1, max + 1):
            n *= i
            n %= mod
            ret.append(n)
    else:
        for i in range(1, max + 1):
            n *= i
            ret.append(n)
    return ret


def mod_invs(max, mod):
    """
    逆元のリスト 0 から max まで
    :param max:
    :param mod:
    :return:
    """
    invs = [1] * (max + 1)
    for x in range(2, max + 1):
        invs[x] = (-(mod // x) * invs[mod % x]) % mod
    return invs


factorials = get_factorials(M * 3 // 2 + N, MOD)
finvs = []
inv = 1
for i in mod_invs(M * 3 // 2 + N, MOD):
    inv = inv * i % MOD
    finvs.append(inv)


def ncr(n, r, mod=None):
    """
    scipy.misc.comb または scipy.special.comb と同じ
    組み合わせの数 nCr
    :param int n:
    :param int r:
    :param int mod: 3 以上の素数であること
    :rtype: int
    """
    if n < r:
        return 0

    # return factorials[n] * mod_inv(factorials[r], mod) * mod_inv(factorials[n - r], mod) % mod
    return factorials[n] * finvs[r] * finvs[n - r] % mod


# 合計が M*3 となる数列の数
# c1 = ncr(M * 3 + N - 1, N - 1, MOD)
# (1) 合計が M*3 で、奇数の数が M 以下である数列の数
c1 = 0
for odds in range(M * 3 % 2, M + 1, 2):
    half = (M * 3 - odds) // 2
    # 合計が half の数列を 2 倍して、odds 個選んで 1 を足す
    c1 += ncr(half + N - 1, N - 1, MOD) * ncr(N, odds, MOD)
    c1 %= MOD

# (2) max が M*2 より大きく、奇数の数が M 以下である数列の数
# c2 = 0
# for mx in range(M * 2 + 1, M * 3 + 1):
#     rem = M * 3 - mx
#     oddmax = M if mx % 2 == 0 else M - 1
#     for odds in range(rem % 2, min(oddmax, rem) + 1, 2):
#         half = (rem - odds) // 2
#         c2 += ncr(half + N - 2, N - 2, MOD) * ncr(N - 1, odds, MOD) * N
#         c2 %= MOD
# print((c1 - c2) % MOD)


# (2) max が M*2 より大きく、奇数の数が M 以下である数列の数
# => 合計が M で、1 要素目が 0 より大きい、奇数が M 以下である数列の数 * N
# 1 要素目に M*2 を足せば (2) になる
# a. 合計が M で奇数が M 以下
c2a = 0
# b. 1 要素目が 0 である数列の数
c2b = 0
for odds in range(M % 2, M + 1, 2):
    half = (M - odds) // 2
    c2a += ncr(half + N - 1, N - 1, MOD) * ncr(N, odds, MOD)
    c2a %= MOD
    c2b += ncr(half + N - 2, N - 2, MOD) * ncr(N - 1, odds, MOD)
    c2b %= MOD

c2 = (c2a - c2b) * N
print((c1 - c2) % MOD)
