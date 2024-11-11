from bisect import bisect
from collections import defaultdict

n = int(input())
up = [defaultdict(list), defaultdict(list), defaultdict(list)]
dp = [defaultdict(list), defaultdict(list), defaultdict(list)]
lp = [defaultdict(list), defaultdict(list), defaultdict(list)]
rp = [defaultdict(list), defaultdict(list), defaultdict(list)]

for _ in range(n):
    x, y, u = input().split()
    x = int(x)
    y = int(y)
    if u == 'U':
        up[0][x].append(y)
        up[1][x + y].append(x)
        up[2][x - y].append(x)
    elif u == 'D':
        dp[0][x].append(y)
        dp[1][x + y].append(x)
        dp[2][x - y].append(x)
    elif u == 'L':
        lp[0][y].append(x)
        lp[1][x + y].append(x)
        lp[2][x - y].append(x)
    else:
        rp[0][y].append(x)
        rp[1][x + y].append(x)
        rp[2][x - y].append(x)


def crush_time(planes1, planes2, idx):
    result = INF
    for xy in planes1[idx]:
        if xy not in planes2[idx]:
            continue
        s = planes1[idx][xy]
        s.sort()
        for x in planes2[idx][xy]:
            i = bisect(s, x)
            if i > 0:
                result = min(result, x - s[i - 1])
    return result


INF = 10 ** 18

ans = min(
    crush_time(up, dp, 0) * 5,
    crush_time(rp, lp, 0) * 5,
    crush_time(rp, up, 1) * 10,
    crush_time(dp, lp, 1) * 10,
    crush_time(up, lp, 2) * 10,
    crush_time(rp, dp, 2) * 10,
)

if ans == 5 * INF:
    print('SAFE')
else:
    print(ans)
