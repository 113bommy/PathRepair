from math import gcd

mod = 1000000007

n = int(input())
counter = {}
zeros = 0
for i in range(n):
    a, b = map(int, input().split())
    if (a == 0 and b == 0):
        zeros += 1
        continue
    g = gcd(a, b)
    a //= g
    b //= g
    if (b < 0):
        a = -a
        b = -b
    if (b == 0 and a < 0):
        a = -a
    counter[(a, b)] = counter.get((a, b), 0)+1

counted = set()
ans = 1
for s, s_count in counter.items():
    if s not in counted:
        if s[0] > 0 and s[1] >= 0:
            t = (-s[1], s[0])
        else:
            t = (s[1], -s[0])
        t_count = counter.get(t, 0)
        now = pow(2, s_count, mod)-1
        now += pow(2, t_count, mod)-1
        now += 1
        ans *= now
        ans %= mod
        counted.add(s)
        counted.add(t)
print((ans - 1 + zeros) % mod)
