# import maths

MOD = 1000000007


def power(a, b, mod=MOD):
    if b == 0:
        return 1
    ans = power(a, b//2, mod)
    ans *= ans
    ans = ans % mod
    if (b % 2) != 0:
        ans *= a
    return ans % mod


def solution(k):
    exp = (1 << k) - 2
    ans = power(4, exp)
    ans *= 6
    return ans % MOD


k = int(input())
ans = solution(k)
print(ans)
