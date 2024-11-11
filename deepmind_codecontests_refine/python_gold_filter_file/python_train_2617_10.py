n, k, a, b = list(map(int, input().split()))
h = [0] + list(map(int, input().split()))
h.sort()

def binp(nu):
    l = 0
    r = len(h) - 1
    while r - l > 1:
        if h[(l + r) // 2] > nu:
            r = (l + r) // 2
        else:
            l = (l + r) // 2
    if h[r] <= nu:
        return l + 1
    else:
        return l

def rec(start, stop, a, b):
    g = binp(start - 1)
    f = binp(stop)
    if g == f:
        return a
    elif stop - start == 0:
        return b * (f - g)
    else:
        return min((stop - start + 1) * (f - g) * b, rec(start, stop - (stop - start + 1) // 2, a, b)
                   + rec((stop - (stop - start + 1) // 2) + 1, stop, a, b))
print(rec(1, 2 ** n, a, b))