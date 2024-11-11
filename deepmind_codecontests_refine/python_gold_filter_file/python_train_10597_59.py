n, m = map(int, input().split())
inf = 10 ** 9
dp = [0] + [inf] * ((1 << n) - 1)
for _ in range(m):
    newdp = [p for p in dp]
    a, b = map(int, input().split())
    c = sum(1 << (int(i) - 1) for i in input().split())
    for bits in range(len(dp)):
        newdp[bits | c] = min(newdp[bits | c], dp[bits] + a)
    dp = newdp
print(-1 if dp[-1] == inf else dp[-1])
