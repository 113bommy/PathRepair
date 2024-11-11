def get_div(b):
    s = {}
    while b != 1:
        for i in range(2, int(b ** 0.5) + 1):
            if b % i == 0:
                s[i] = s.get(i, 0) + 1
                b //= i
                break
        else:
            s[b] = s.get(b, 0) + 1
            return s
    return s

n, b = map(int, input().split())

h = get_div(b)
p = 10**100

for i in h:
    total = 0
    for j in range(1, 1000):
        total += n // (i ** j)
    total //= h[i]
    p = min(total, p)

print(p)
    