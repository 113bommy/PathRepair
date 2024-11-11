n, k = map(int, input().split())
ps = list(map(int, input().split()))


g = [None for i in range(256)]
f = [None for i in range(256)]
ans = []
for i in range(n):
    p = ps[i]
    if g[p] is not None:
        ans.append(g[p])
        f[p] = 1
    else:
        gb= 0
        for j in range(k):
            ind = p - j
            if f[ind] is not None:
                gb = ind +1
                break
            if ind <= 0:
                break
            if j == k-1:
                gb = ind
        ans.append(gb)
        for j in range(k):
            if gb+j >= 256:
                break
            if f[gb + j] is None:
                g[gb+j] = gb
            else:
                break
        f[gb] = 1
        f[p] = 1
print(' '.join([str(i) for i in ans]))