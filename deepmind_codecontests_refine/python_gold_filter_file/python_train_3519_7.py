import bisect

N, K = [int(x) for x in input().split()]
V = [int(x) for x in input().split()]
M = min(N, K)

ans = 0
juwel = []
for l in range(M + 1):
    for r in range(M - l + 1):
        juwel = sorted(V[:l] + V[N - r:])
        s = bisect.bisect_left(juwel, 0)
        s = min(s, K - l - r)
        juwel = juwel[s:]
        ans = max(ans, sum(juwel))

print(ans)