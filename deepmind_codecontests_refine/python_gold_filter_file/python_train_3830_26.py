n, k = map(int, input().split())
a = list(map(int, input().split()))

a.sort()

def check(t):
    j = n - 1 if t > 0 else 0
    res = 0
    f = 1

    cond = lambda x, t, f:x <= t if f * t > 0 or (t == 0 and f == -1) else x > t
    shift = lambda x, t:x-1 if t > 0 else x+1
    count = lambda x, n, f:n-x if f == 1 else x

    for ai in a:
        if f == 1 and ai > 0:
            f = -1
            j = n - 1 if t > 0 else 0
        if ai:
            while j >= 0 and j < n and cond(ai * a[j], t, f):
                j = shift(j, t)
            if t > 0:
                res += count(j+1, n, f)
            else:
                res += count(j, n, f)
        else:
            if t >= 0:
                res += n
        if ai * ai <= t:
            res -= 1
    return res // 2
            

m = max(max(a)**2, min(a)**2)
l = -m
r = m

while r - l > 1:
    mid = (l + r) // 2
    if check(mid) < k:
        l = mid
    else:
        r = mid

if check(l) == k:
    print(l)
else:
    print(r)
