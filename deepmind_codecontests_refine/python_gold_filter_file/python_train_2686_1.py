import os
import sys

if os.getenv("LOCAL"):
    sys.stdin = open("_in.txt", "r")

sys.setrecursionlimit(2147483647)
INF = float("inf")
IINF = 10 ** 18
MOD = 10 ** 9 + 7

P = int(sys.stdin.readline())
A = list(map(int, sys.stdin.readline().split()))


# 解説AC


def mod_invs(max, mod):
    """
    逆元のリスト 0 から max まで
    :param int max:
    :param int mod:
    """
    invs = [1] * (max + 1)
    for x in range(2, max + 1):
        invs[x] = (-(mod // x) * invs[mod % x]) % mod
    return invs


def get_ncrs(n, mod):
    """
    nC_0, nC_1, nC_2, ..., nC_n までのリスト
    :param n:
    :param mod:
    :return:
    """
    invs = mod_invs(n, mod)
    ret = [1]
    ncr = 1
    for i in range(1, n + 1):
        ncr = ((ncr * (n - i + 1) % mod) * invs[i]) % mod
        ret.append(ncr)
    return ret


ncr = get_ncrs(P - 1, P)


def poly(j):
    # 1 - (x-j)^(P-1) は x == j のときだけ 1、それ以外のとき 0 になる
    # 1 - (x-j)^(P-1) の係数
    coef = []
    c = 1
    for i in range(P):
        coef.append(-ncr[i] * c)
        c = c * -j % P
    coef.reverse()
    coef[0] += 1
    return coef


ans = [0] * P
for j, a in enumerate(A):
    if a == 1:
        for k, b in enumerate(poly(j)):
            ans[k] += b
            ans[k] %= P
print(*ans)

#
# def f(x, B):
#     ret = 0
#     for i, b in enumerate(B):
#         ret += b * x ** i
#         ret %= P
#     return ret
#
#
# hist = []
# for B in itertools.product(range(P), repeat=P):
#     r = []
#     for x in range(P):
#         a = f(x, B)
#         r.append(a)
#     if [a for a in r if a >= 2]:
#         continue
#     hist.append((r, list(B)))
# hist.sort()
# for r, B in hist:
#     print('a: {}, b: {}'.format(r, B))
# print()
#
# # for P in [2, 3, 5, 7, 11, 13, 17, 19, 23]:
# for P in [3, 5, 7]:
#     print(P)
#     t = []
#     # x_i mod P
#     for x in range(P):
#         s = []
#         for e in range(P):
#             s.append(x ** e % P)
#             # s.append(x ** e)
#         print(x, s)
#         t.append(s)
#     ss = []
#     for x in range(P):
#         s = 0
#         for i in range(P):
#             s += t[i][x]
#         ss.append(s % P)
#     print('s', ss)
#     print()
