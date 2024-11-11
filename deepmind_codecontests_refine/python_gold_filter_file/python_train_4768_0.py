import sys


def prepare(n, MOD):
    f = 1
    factorials = [1]
    for m in range(1, n + 1):
        f *= m
        f %= MOD
        factorials.append(f)
    inv = pow(f, MOD - 2, MOD)
    invs = [1] * (n + 1)
    invs[n] = inv
    for m in range(n, 1, -1):
        inv *= m
        inv %= MOD
        invs[m - 1] = inv

    solo_invs = [0] + [f * i % MOD for f, i in zip(factorials, invs[1:])]

    return factorials, invs, solo_invs


def decompose_inverses(solo_invs, MOD):
    # 各整数 g に対して、g の約数である各 i について dcm[i] を全て足すと 1/g になるような数列を作成
    n = len(solo_invs)
    dcm = solo_invs[:]
    for i in range(1, n):
        d = dcm[i]
        for j in range(2 * i, n, i):
            dcm[j] -= d
    for i in range(1, n):
        dcm[i] %= MOD
    return dcm


n, *aaa = map(int, sys.stdin.buffer.read().split())
MOD = 998244353
LIMIT = max(aaa)
count = [0] * (LIMIT + 1)
double = [0] * (LIMIT + 1)
for a in aaa:
    count[a] += a
    double[a] += a * a
_, _, solo_invs = prepare(LIMIT, MOD)
dcm = decompose_inverses(solo_invs, MOD)

ans = 0
inv2 = solo_invs[2]
for d in range(1, LIMIT + 1):
    ans = (ans + dcm[d] * (sum(count[d::d]) ** 2 - sum(double[d::d])) * inv2) % MOD
print(ans)
