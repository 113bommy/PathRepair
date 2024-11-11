ss = sorted(set(map(int, input().split())))
input()
nn = sorted(set(map(int, input().split())))
if len(nn) == 1:
    print(0)
elif len(ss) == 1:
    print(nn[-1] - nn[0])
else:
    n0 = nn[0]
    ans = int(1e9)
    for s in ss:
        n0f = n0 - s
        lrs = []
        for n in nn[1:]:
            l = r = int(1e9)
            for s in ss:
                f = n - s
                if f == n0f:
                    break
                if f > n0f:
                    r = min(r, f - n0f)
                else:
                    l = min(l, n0f - f)
            else:
                lrs.append([l, r])
        if not lrs:
            ans = 0
            break
        lrs.sort()
        rls = sorted(lrs, key=lambda x: x[1], reverse=True)
        ansc = rls[0][1]
        nrls = len(rls)
        ir = 0
        for lr in lrs:
            lr[1] = 0
            while ir < nrls and rls[ir][1] == 0:
                ir += 1
            r = rls[ir][1] if ir < nrls else 0
            ansc = min(ansc, lr[0] + r)
        ans = min(ans, ansc)
    print(ans)
