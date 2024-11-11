import math
from fractions import Fraction as frac

MOD = 1e9 + 7

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

def lcm(a, b):
    return a * b // gcd(a, b)

def solve(case_no):
    n = int(input())
    ans = (n // 3) * 2
    n -= (n // 3) * 3
    if n >= 1:
        ans += 1
    print(ans)

t = 1
# t = int(input())
for i in range(1, t + 1):
    solve(i)
