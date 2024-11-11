def run():
    n, k, a, b = int(input()), int(input()), int(input()), int(input())
    if n == 1:
        print(0)
        return
    if k == 1:
        print((n-1) * a)
        return
    r = 0
    while True:
        if n < k:
            print(r + (n-1)*a)
            return
        rem = n % k
        if rem != 0:
            r += a*rem
            n -= rem
            continue

        decr = n - (n//k)
        r += min(b, decr * a)
        n = n // k

        # if n == k:
        #     print(r + b)
        #     return
        # rem = n % k
        # if rem == 0:
        #     r += b
        #     n = n // k
        #     continue
        # r += a*rem
        # n -= rem


run()