def solve():
    from bisect import bisect_left, bisect_right

    N, K = map(int, input().split())
    As = list(map(int, input().split()))

    As.sort()
    negAs = [-A for A in As[::-1]]
    A2s = [A*A for A in As]
    A2s.sort()

    pstvBs = []
    numB0= 0
    ngtvBs = []
    for A in As:
        if A > 0:
            pstvBs.append(A)
        elif A == 0:
            numB0 += 1
        else:
            ngtvBs.append(A)

    def isOK(x):
        if x >= 0:
            dire = 1
        else:
            dire = -1
        num = 0
        # 正
        iA = 0
        for B in pstvBs[::-dire]:
            key = x//B
            while iA < N and As[iA] <= key:
                iA += 1
            num += iA
        # ゼロ
        if x >= 0:
            num += N*numB0
        # 負
        iA = 0
        for B in ngtvBs[::dire]:
            key = x//(-B)
            while iA < N and negAs[iA] <= key:
                iA += 1
            num += iA
        i = bisect_right(A2s, x)
        num -= i
        num //= 2
        return num >= K

    ng, ok = -(10**18)-1, 10**18+1
    while abs(ok-ng) > 1:
        mid = (ng+ok) // 2
        if isOK(mid):
            ok = mid
        else:
            ng = mid

    print(ok)


solve()
