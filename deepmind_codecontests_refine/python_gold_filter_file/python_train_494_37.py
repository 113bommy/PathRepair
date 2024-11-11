import math
from collections import Counter

MOD = 10**9 + 7
N = int(input())

I = []
zz = 0
sz = 0
tz = 0
for _ in range(N):
    a,b = map(int, input().split())

    # (a, b) = (0, 0)
    if a == 0 and b == 0:
        zz += 1
        continue
    # (a, b) = (0, #)
    if a == 0:
        sz += 1
        continue
    # (a, b) = (#, 0)
    if b == 0:
        tz += 1
        continue

    gcd = math.gcd(a, b)
    if b < 0:
        a *= -1
        b *= -1
    I.append((a//gcd,b//gcd))

S = []
T = []
C = Counter(I)
for a, b in C.keys():
    if a > 0:
        S.append(C[(a,b)])
        T.append(C[(-b,a)])
    else:
        if C[(b,-a)] == 0:
            S.append(0)
            T.append(C[(a,b)])

ans = 1
ans *= 2**sz + 2**tz - 1
ans %= MOD
for i in range(len(S)):
    ans *= 2**S[i] + 2**T[i] - 1
    ans %= MOD
ans += zz  # (0, 0)
ans -= 1
print(ans % MOD)