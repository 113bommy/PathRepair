import math
a, b, n = [int(x) for x in input().split()]

for i in range(n):
    l, t, m = [int(x) for x in input().split()]
    x = a + (l - 1) * b
    if x > t:
        print("-1")
        continue

    r = (t - a) // b + 1
    D = (2 * x - b) ** 2 + 8 * m * t * b
    d = int(math.floor((-2 * x + b + math.sqrt(D)) / (2 * b)))
    r = min(r, l + d - 1)
    # total = t * m
    # last = a + (r - 1) * b
    # total_need = (x + last) * (r - l + 1) // 2
    # while total_need > total:
    #     total_need -= last
    #     last -= b
    #     r -= 1
    print(r)
