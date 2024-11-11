n, k, t = [int(x) for x in input().split()]
if t <= k:
    print(t)
elif t >= n:
    r = k+n-t
    if r < 0:
        r = 0
    print(r)
else:
    print(k)