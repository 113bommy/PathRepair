MOD = int(1e9+9)

def fast_power(x, y):
    res = 1 
    while y > 0:
        if y % 2 == 1: 
            res = res * x%MOD
        x = x * x % MOD
        y //= 2
    return res
 
n, m, k = map(int, input().split())
x = max(0, m - n // k * (k - 1) - n % k)
z = (m - x * k) % MOD
res = fast_power(2, x+1)
res = (res - 2) % MOD * k % MOD
res = (res + z) % MOD
print(res)
