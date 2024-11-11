for _ in range(int(input())):
    n = int(input())
    h = list(map(int, input().split()))
    l = 0
    r = 10 ** 9 + 10
    while r - l > 1:
        m = (l + r) // 2
        k = h.copy()
        flag = True
        for i in range(n - 1, 1, -1):
            if k[i] < m:
                flag = False
                break
            d = (k[i] - m) // 3
            if d * 3 > h[i]:
                # if h[i] < m:
                #     flag = False
                #     break
                d = h[i] // 3
            k[i - 1] += d
            k[i - 2] += 2 * d
        # print()
        if k[0] < m or k[1] < m:
            flag = False
        if flag:
            l = m
        else:
            r = m
    print(l)
