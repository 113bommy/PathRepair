from math import gcd

MOD = 10**9+7
N = int(input())
d = {}
zero = 0
for i in range(N):
    a, b = map(int, input().split())
    if a == 0 and b == 0:
        zero += 1
        continue

    flip = 0
    while not (a >= 0 and b > 0):
        a, b = -b, a
        flip ^= 1

    g = gcd(a, b)
    a //= g
    b //= g
    if not (a, b) in d:
        d[(a, b)] = [0, 0]
    d[(a, b)][flip] += 1

ans = 1
for (v1, v2) in d.values():
    ans *= pow(2, v1, MOD) + pow(2, v2, MOD)-1
    ans %= MOD
ans -= 1
ans += zero
ans %= MOD
print(ans)
