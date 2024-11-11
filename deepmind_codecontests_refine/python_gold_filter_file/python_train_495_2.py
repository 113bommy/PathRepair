import sys

sys.setrecursionlimit(1000000)
input = lambda : sys.stdin.readline().rstrip()

def pow_mod(x, y, mod):
    tmp = x
    ret = 1
    while y > 0:
        if y % 2 == 1:
            ret = ret * tmp % mod
        tmp = tmp * tmp % mod
        y //= 2
    return ret

def inverse(x, mod):
    return pow_mod(x, mod - 2, mod)

N = int(input())
x = list(map(int, input().split()))

MOD = 1000000007

def factorial(x):
    if x <= 1:
        return 1
    else:
        return x * factorial(x - 1) % MOD

f = factorial(N - 1)

h = [0]
for _ in range(N):
    h.append((h[-1] + f * inverse(len(h), MOD)) % MOD)

ans = 0
for i in range(N - 1):
    ans += h[i + 1] * (x[i + 1] - x[i])
    ans %= MOD

print(ans)