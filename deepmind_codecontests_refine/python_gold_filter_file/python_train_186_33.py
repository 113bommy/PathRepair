N, K, Q = map(int, input().split())
A = list(map(int, input().split()))

def calc(x):
    grp = [[]]
    for a in A:
        if a < x and len(grp[-1]) > 0:
            grp.append([])
        if a >= x:
            grp[-1].append(a)
    L = []
    for g in grp:
        g.sort()
        L.extend(g[:max(0, len(g) - K + 1)])
    L.sort()

    if len(L) < Q or L[0] != x:
        return 10**18
    return L[Q - 1] - x

ans = 10**18
for a in A:
    ans = min(ans, calc(a))
print(ans)
