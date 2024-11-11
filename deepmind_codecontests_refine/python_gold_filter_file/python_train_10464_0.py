# Contest: 21 - Codeforces Rating >= 2200 (https://a2oj.com/ladder?ID=21)
# Problem: (27) Multipliers (Difficulty: 5) (http://codeforces.com/problemset/problem/615/D)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


from itertools import groupby
from functools import reduce
MOD = 10**9 + 7
n = rint()
p = rints()
p.sort()
p2 = [(k, sum(1 for _ in g)) for k, g in groupby(p)]

prefdivs = [0] * len(p2)
prefdivs[0] = p2[0][1] + 1
for i in range(1, len(p2)):
    prefdivs[i] = (prefdivs[i - 1] * (p2[i][1] + 1)) % (MOD - 1)

suffdivs = [0] * len(p2)
suffdivs[-1] = p2[-1][1] + 1
for i in reversed(range(len(p2) - 1)):
    suffdivs[i] = (suffdivs[i + 1] * (p2[i][1] + 1)) % (MOD - 1)

res = 1
for i, (pi, e) in enumerate(p2):
    remdivs = (1 if i == 0 else prefdivs[i - 1]) * (1 if i + 1 == len(p2) else suffdivs[i + 1]) % (MOD - 1)
    res = (res * pow(pi, e * (e + 1) // 2 * remdivs % (MOD - 1), MOD)) % MOD
print(res)
