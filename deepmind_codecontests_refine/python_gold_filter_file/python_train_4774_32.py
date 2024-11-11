#!/usr/bin/env python3
def solve():
    N, M_a, M_b = [int(x) for x in input().split()]
    inf = 100000
    t = [[inf] * (10 * N + 1) for _ in range(10 * N + 1)]
    t[0][0] = 0
    for _ in range(N):
        ai, bi, ci = [int(x) for x in input().split()]
        for ta in reversed(range(ai, len(t))):
            for tb in reversed(range(bi, len(t[0]))):
                t[ta][tb] = min(t[ta][tb], t[ta - ai][tb - bi] + ci)
    ans = min(
        t[k * M_a][k * M_b]
        for k in range(1, min((len(t) - 1) // M_a, (len(t[0]) - 1) // M_b) + 1)
    )
    print(-1 if ans >= inf else ans)


solve()
