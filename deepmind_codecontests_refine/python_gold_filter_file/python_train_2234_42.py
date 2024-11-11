def dreaMoon(n, m):
    j = 0
    while n > 0:
        s = (n // 2) + (n % 2) + j
        if s % m == 0:
            return s
        j += 1
        n -= 1
    return -1

n, m = map(int, input().split())
print(dreaMoon(n, m))
