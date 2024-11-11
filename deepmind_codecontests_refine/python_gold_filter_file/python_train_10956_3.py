for _ in range(int(input())):
    n, m = map(int, input().split())
    a = [int(input(), 2) for _ in range(n)]
    x = (2 ** m - n - 1) // 2
    for v in sorted(a):
        if v <= x:
            x += 1
    print("{0:0={1}b}".format(x, m))
