import sys

d, k, a, b, t = map(int, input().split())
if d <= k:
    print(d * a)
    exit()

d -= k


def solve1():
    x = (d + k - 1) // k
    return t * x + a * d


def solve2():
    x = d // k
    y = d % k
    return (t + a * k) * x + b * y


def solve3():
    return d * b


print(
    min(solve1(), solve2(), solve3()) + a * k
)
