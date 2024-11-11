n = int(input())
ga, sa, ba = map(int, input().split())
gb, sb, bb = map(int, input().split())

def trade(n, rate):
    dp = [0]
    r = sorted(rate, key=lambda r: float(r[0]) / float(r[1]))[0]
    p = n - 10000000
    if p // r[0] > 0:
        d = p // r[0]
        n -= d * r[0]
        dp = [d * r[1]]
    for i in range(n):
        v = dp[i] + 1
        for ra, rb in rate:
            if i + 1 >= ra:
                v = max(v, dp[i + 1 - ra] + rb)
        dp.append(v)
    return dp[-1]

n = trade(n, [(ga, gb), (sa, sb), (ba, bb)])
n = trade(n, [(gb, ga), (sb, sa), (bb, ba)])
print(n)
