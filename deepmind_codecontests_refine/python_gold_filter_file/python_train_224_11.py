for _ in range(int(input())):
    L, R = 0, 10 ** 9 + 1
    for _ in range(int(input())):
        l, r = map(int, input().split())
        L = max(L, l)
        R = min(R, r)
    print(max(0, L - R))