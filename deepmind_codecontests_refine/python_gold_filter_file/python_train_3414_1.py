from fractions import gcd
MOD = 1000000007
def pw(x, y):
    ans = 1
    while y > 0:
        if y % 2:
            ans = ans * x % MOD
        x = x * x % MOD
        y //= 2
    return ans
H, W, T = map(int, input().split())
HT = gcd(H, T)
WT = gcd(W, T)
H //= HT
W //= WT
print(pw(pw(2, H) + pw(2, W) + pw(2, gcd(H, W)) - 3, HT * WT))