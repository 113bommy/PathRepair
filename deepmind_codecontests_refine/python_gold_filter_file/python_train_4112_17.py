n = int(input())
res = 0
for i in range(10):
    if n >= 10 ** i:
        if n > (10 ** (i + 1)) - 1:
            res += (9 * 10 ** i) * (i + 1)
        else:
            res += (n - 10 ** i + 1) * (i + 1)
            print(res)
            exit()