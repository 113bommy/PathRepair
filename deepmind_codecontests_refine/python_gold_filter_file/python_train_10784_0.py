t = int(input())
for _ in range(t):
    x, y, p, q = map(int, input().split())
    if p == q:
        print(0 if x == y else -1)
    elif p == 0:
        print(0 if x == 0 else -1)
    elif x * q == y * p:
        print(0)
    else:
        l = 0
        r = 2**64
        cnt = 0
        while l + 1 < r:
            cnt += 1
            c = (l + r) // 2
            if x <= c * p <= x + c * q - y:
                r = c
            else:
                l = c
        print(r * q - y)
