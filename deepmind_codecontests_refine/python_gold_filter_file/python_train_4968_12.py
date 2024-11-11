n = int(input())

l, r = 0, 10 ** 18


def enough(n, k):
    was = n
    eaten = 0
    while n > 0:
        eaten += min(n, k)
        n -= k
        if n > 0:
            n -= n // 10
    return 2 * eaten >= was


while l + 1 < r:
    m = (l + r) // 2
    if not enough(n, m):
        l = m
    else:
        r = m
print(r)
