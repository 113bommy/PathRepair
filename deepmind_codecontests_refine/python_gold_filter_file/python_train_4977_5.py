from itertools import accumulate
import sys
input = sys.stdin.readline

def solve():
    N, X = map(int, input().split())
    tests = []
    D0 = 0
    for _ in range(N):
        B, L, U = map(int, input().split())
        v = L*B + U*(X-B)
        tests.append((v, B, L, U))
        D0 -= L*B
    tests.sort(reverse=True)
    accVs = list(accumulate([0] + tests, lambda accX, X: accX + X[0]))

    def isOK(k):
        q = k // X
        r = k % X
        accV = accVs[q+1]
        for v, B, L, U in tests[:q]:
            d = D0 + accV - v
            if r <= B:
                d += L*r
            else:
                d += L*B + U*(r-B)
            if d >= 0:
                return True
        accV = accVs[q]
        for v, B, L, U in tests[q:]:
            d = D0 + accV
            if r <= B:
                d += L*r
            else:
                d += L*B + U*(r-B)
            if d >= 0:
                return True
        return False

    ng, ok = -1, N*X
    while abs(ok-ng) > 1:
        mid = (ng+ok) // 2
        if isOK(mid):
            ok = mid
        else:
            ng = mid

    return ok


print(solve())
