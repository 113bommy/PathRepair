import bisect
import sys
A, B, Q = map(int, input().split())
INF = 10 ** 13
s = [-INF] + [int(input()) for i in range(A)] + [INF]
t = [-INF] + [int(input()) for i in range(B)] + [INF]
xs = [int(sys.stdin.readline()) for i in range(Q)]
for x in xs:
    b, d = bisect.bisect_right(s, x), bisect.bisect_right(t, x)
    res = INF
    for S in [s[b - 1], s[b]]:
        for T in [t[d - 1], t[d]]:
            d1, d2 = abs(S - x) + abs(T - S), abs(T - x) + abs(S - T)
            res = min(res, d1, d2)
    print(res)