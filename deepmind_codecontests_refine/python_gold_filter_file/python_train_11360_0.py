import io, os
input = io.StringIO(os.read(0, os.fstat(0).st_size).decode()).readline

ii = lambda: int(input())
mi = lambda: map(int, input().split())
li = lambda: list(mi())

out = []
for _ in range(ii()):
    n, m, t = mi()
    p = li()

    def check(d):
        cur = tim = tot = totim = 0
        for i in range(n):
            x = p[i]
            if x > d: continue
            totim += x
            tim += x
            if totim > t: break
            cur += 1
            tot += 1
            if cur == m:
                totim += tim
                if totim > t: break
                cur = tim = 0
        return all(x > d for x in p[i+1:]), tot

    lo, hi = 1, t
    while lo < hi:
        mid = (lo + hi + 1) >> 1
        if check(mid)[0]:
            lo = mid
        else:
            hi = mid - 1

    if check(lo + 1)[1] > check(lo)[1]:
        lo += 1

    out.append('%d %d' % (check(lo)[1], lo))

print(*out, sep='\n')