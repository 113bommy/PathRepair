def fact(n):
    v = 1
    while n > 1:
        v *= n
        n -= 1
        v %= 10**9+7
    return v

n = int(input())
f = fact(n)
u = 2 ** (n-1)

print((f-u) % (10**9+7))
