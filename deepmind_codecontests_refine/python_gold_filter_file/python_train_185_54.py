def usage():
    c, n = map(int, input().split())
    if c == 1:
        print(n)
        return 0
    ans = 1
    fct = factorize(n)
    for i in range(len(fct)):
        if fct[i][1] >= c:
            ans *= fct[i][0] ** (fct[i][1] // c)
    print(ans)


def factorize(n):
    fct = []
    b, e = 2, 0
    while b * b <= n:
        while n % b == 0:
            n = n // b
            e = e + 1
        if e > 0:
            fct.append((b, e))
        b, e = b + 1, 0
    if n > 1:
        fct.append((n, 1))
    return fct


if __name__ == '__main__':
    usage()
