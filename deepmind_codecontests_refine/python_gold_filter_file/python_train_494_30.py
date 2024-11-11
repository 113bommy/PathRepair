from collections import defaultdict
from math import gcd
MOD = 1000000007
inpl = lambda: list(map(int,input().split()))
groups = defaultdict(int)
null = 0
N = int(input())
for _ in range(N):
    A, B = inpl()
    if A == 0 and B == 0:
        null += 1
    elif A == 0:
        groups[(0,1)] += 1
    elif B == 0:
        groups[(1,0)] += 1
    else:
        g = gcd(A,B)
        A //= g
        B //= g
        if A < 0:
            A *= -1
            B *= -1
        groups[(A, B)] += 1
ans = 1
for k in list(groups.keys()):
    A, B = k
    if B <= 0:
        C, D = -B, A
    else:
        C, D = B, -A
    groups[(C,D)]
for k, v in groups.items():
    A, B = k
    if B <= 0:
        continue
    u = groups[(B,-A)]
    p = pow(2,v,MOD) + pow(2,u,MOD) - 1
    ans *= p
    ans %= MOD
ans -= 1
ans += null
print(ans % MOD)
