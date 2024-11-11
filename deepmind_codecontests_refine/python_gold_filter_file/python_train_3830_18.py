from bisect import bisect_left

def binsearch(l, r, fn):
    while r - l > 1:
        m = (l + r) // 2
        if fn(m):
            l = m
        else:
            r = m
    return l


def main():
    N, K = list(map(int, input().split()))
    A = sorted(list(map(int, input().split())))
    p = bisect_left(A, 0)
    An = A[:p]
    Ap = A[p:]

    if K <= p * (N - p):
        def helper(x):
            t = 0
            r = 0
            for p in Ap:
                while t < len(An) and An[t] * p <= x:
                    t += 1
                r += t
            return r < K
        l = binsearch(Ap[-1] * An[0] - 1, 1, helper)
    else:
        K -= p * (N - p)
        An.reverse()
        def helper(x):
            r = 0
            for a in [Ap, An]:
                t = len(a) - 1
                for i, p in enumerate(a):
                    if t <= i:
                        break
                    while t > i and a[t] * p > x:
                        t -= 1
                    r += t - i
            return r < K 
        m = Ap[-1]
        if An:
            m = max(m, -An[-1])
        l = binsearch(-1, m * m, helper)
    print(l + 1)


main()
