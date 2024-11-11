def gcd(a, b):
    r = a % b
    if r:
        return gcd(b, r)
    return b


def lcm(a, b):
    if a < b:
        a, b = b, a
    return a * b // gcd(a, b)


def min_weight(m):
    p, q, r, b = bars[m - 1]
    red = p * (min_weight(r) if r else 1)
    blue = q * (min_weight(b) if b else 1)
    equilibrium = lcm(red, blue)
    return equilibrium // p + equilibrium // q


while True:
    n = int(input())
    if not n:
        break

    bars = [tuple(map(int, input().split())) for _ in range(n)]

    root_bar = set(range(1, n + 1))
    for _, _, r, b in bars:
        if r: root_bar.remove(r)
        if b: root_bar.remove(b)

    print(min_weight(root_bar.pop()))