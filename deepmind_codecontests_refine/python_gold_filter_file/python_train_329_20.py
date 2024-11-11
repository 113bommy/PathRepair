n, p, w, d = map(int, input().split())

res = 0
for i in range(0, w):
    if ((p - i * d) % w == 0) and (p - i * d >= 0):
        if (((p - i * d) // w) + i <= n):
            print((p - i * d) // w, i, n - (p - i * d) // w - i)
            res = 1
            break
if res == 0: print('-1')