n,m,k = [int(x) for x in input().split()]
k += 1
if k <= n:
    print("%d 1" % k)
else:
    k -= n
    l = (k - 1) // (m - 1)
    lres = n - l
    r = k % (m - 1)
    if l % 2 == 0:
        rres = 1 + r
        if r == 0:
            rres = m
    else:
        if r == 0:
            rres = 2
        else:
            rres = m - r + 1
    print("%d %d" % (lres,rres))