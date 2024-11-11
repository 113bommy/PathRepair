from math import gcd


def solve():
    l = int(input())
    div = 1
    arr = list(map(int, input().split()))
    for i in range(l):
        val = lcm(div, i+2)
        if div < 10**9:
            div = val
        if arr[i] % div == 0:
            return "NO"
    return "YES"


def lcm(a, b):
    return a*b//gcd(a, b)


n = int(input())
for i in range(n):
    print(solve())
