import math

n, m, k = map(int, input().split(' '))
MOD = int(1e9+7)
if k == 1 or k > n:
    print(m**n % MOD)
elif k == n:
    print((m**(n//2) * (m if k % 2 == 1 else 1)) % MOD)
elif k % 2 != 0:
    print((m*(m-1) + m) % MOD)
else:
    print(m)